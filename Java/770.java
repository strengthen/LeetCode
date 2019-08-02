__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        Map<String, Integer> variables = new HashMap<>();
        for (int i=0; i<evalvars.length; i++) {
            variables.put(evalvars[i], evalints[i]);
        }
        Expression l0=Expression.create(0), l1 = Expression.create(1);
        Expression o0 = Expression.create(1);
        boolean isSign = true;
        int sign = 1;
        Stack<Expression> stack = new Stack<>();
        for (int i=0; i<expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == ' ' || c =='*') {
              continue;  
            } else if (Character.isDigit(c)) { //number
                int num=0;
                while (i<expression.length() && Character.isDigit(expression.charAt(i))) {
                    num = num*10 + (expression.charAt(i)-'0');
                    i++;
                }
                i--;
                l1 = Expression.mul(l1, Expression.create(sign*num));
                isSign = false;
                sign = 1;
            } else if (Character.isLetter(c)) { //variable
                StringBuilder sb = new StringBuilder();
                while (i<expression.length() && Character.isLetter(expression.charAt(i))) {
                    sb.append(expression.charAt(i++));
                }
                i--;
                String varStr = sb.toString();
                Expression exp;
                if (variables.containsKey(varStr)) {
                    exp = Expression.create(sign*variables.get(varStr));
                } else {
                    exp = Expression.create(varStr, sign);
                }
                l1 = Expression.mul(l1, exp);
                isSign = false;
                sign = 1;
            } else if (c == '(') {
                stack.push(l0);
                stack.push(l1);
                stack.push(o0);
                l0=Expression.create(0);
                l1 = Expression.create(1);
                o0=Expression.create(1);
                isSign = true;
                sign = 1;
            } else if (c == ')') {
                l0 = Expression.add(l0, Expression.mul(o0, l1));
                o0 = stack.pop();
                l1 = Expression.mul(stack.pop(), l0);
                l0 = stack.pop();
                isSign = false;
            } else if (c=='+' || c == '-') {           
                if (!isSign) {
                    l0 = Expression.add(l0, Expression.mul(o0, l1));
                    l1 = Expression.create(1);
                    if (c == '-') {
                        o0 = Expression.create(-1);
                    } else {
                        o0 = Expression.create(1);
                    }
                } else if (c=='-') {
                    sign = sign * -1;
                }
                isSign = true;
            } 
        }
        l0 = Expression.add(l0, Expression.mul(o0, l1));
        List<String> result = new ArrayList<>(l0.terms.size());
        for (Term term : l0.terms) {
            result.add(term.toString());
        }
        return result;
    }
    
    private static class Expression {
        List<Term> terms;
        public Expression(List<Term> terms) {
            this.terms = terms;
        }
        
        public void print() {
            System.out.print("[");
            for (Term term : terms)
                System.out.print(term + ", ");
            System.out.print("]");
            System.out.println();
        }
        
        public static Expression create(String variable, int coef) {
            if (coef == 0) return new Expression(new ArrayList<>());
            return new Expression(Arrays.asList(new Term(coef, new String[]{variable})));
        }
        
        public static Expression create(int variable) {
            if (variable == 0) return new Expression(new ArrayList<>());
            return new Expression(Arrays.asList(new Term(variable, new String[0])));
        }
        
        public static Expression add (Expression e1, Expression e2) {
            int i=0,j=0;
            List<Term> terms = new ArrayList<>();
            while (i<e1.terms.size() || j<e2.terms.size()) {
                if (i>=e1.terms.size() || (j<e2.terms.size() && e2.terms.get(j).compareTo(e1.terms.get(i)) < 0) ) {
                    terms.add(e2.terms.get(j++));
                } else if (j>=e2.terms.size() || (i<e1.terms.size() && e2.terms.get(j).compareTo(e1.terms.get(i)) > 0) ){
                    terms.add(e1.terms.get(i++));
                } else {
                    int coefficient = e1.terms.get(i).coefficient + e2.terms.get(j++).coefficient;
                    if (coefficient != 0) {
                        terms.add(new Term(coefficient, e1.terms.get(i).freeVariables));
                    }
                    i++;
                }
            }
            return new Expression(terms);
        }
        
        public static Expression mul(Expression e1, Expression e2) {
            List<Term> newTerms = new ArrayList<>(e1.terms.size() + e2.terms.size());
            for (Term t1 : e1.terms) {
                for (Term t2 : e2.terms) {
                    newTerms.add(Term.mul(t1, t2));
                }
            }
            Collections.sort(newTerms);
            List<Term> finalTerms = new ArrayList<>(newTerms.size());
            for (Term term : newTerms) {
                if (finalTerms.size() == 0 || finalTerms.get(finalTerms.size()-1).compareTo(term) != 0) {
                    finalTerms.add(term);
                } else {
                    Term temp = finalTerms.get(finalTerms.size()-1);
                    finalTerms.remove(finalTerms.size()-1);
                    int coefficient =  temp.coefficient + term.coefficient;
                    if (coefficient != 0) {
                        finalTerms.add(new Term(coefficient, temp.freeVariables));
                    }
                }
            }
            Expression e3 = new Expression(finalTerms);
            //e1.print(); System.out.println("*");e2.print();System.out.println("=");e3.print();
            return e3;
        }
    }
    
    private static class Term implements Comparable<Term> {
        int coefficient;
        String freeVariables[];
        public Term(int coefficient, String freeVariables[]) {
            this.coefficient = coefficient;
            this.freeVariables = freeVariables;
        }
        
        public static Term mul(Term t1, Term t2) {
            int newCoefficient = t1.coefficient * t2.coefficient;
            String[] newFreeVariables = new String[t1.freeVariables.length+t2.freeVariables.length];
            int i=0, j=0;
            while (i<t1.freeVariables.length || j<t2.freeVariables.length) {
                if (i>=t1.freeVariables.length || (j<t2.freeVariables.length && t1.freeVariables[i].compareTo(t2.freeVariables[j])>0)) {
                    newFreeVariables[i+j] = t2.freeVariables[j++];
                } else {
                    newFreeVariables[i+j] = t1.freeVariables[i++];
                }
            }
            return new Term(newCoefficient, newFreeVariables);
        }
        
        @Override
        public int compareTo(Term t2) {
            int result = Integer.compare(t2.freeVariables.length, this.freeVariables.length);
            if (result != 0) return result;
            for (int i=0; i<this.freeVariables.length; i++) {
                result = this.freeVariables[i].compareTo(t2.freeVariables[i]);
                if (result != 0) return result;
            }
            return 0;
        }
        
        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(coefficient);
            sb.append('*');
            for (String freeVariable : freeVariables) {
                sb.append(freeVariable);
                sb.append('*');
            }
            sb.setLength(sb.length()-1);
            return sb.toString();
        }
        
    }
}
__________________________________________________________________________________________________
sample 39 ms submission
class Solution {
    Map<String,Integer> map=new HashMap<>(); //evaluation map
    class Term
    {
        int para=1; //the parameter of this term
        List<String> var=new ArrayList<>(); //each factor (e.a. a*b*b*c->{a,b,b,c})
        @Override
        public String toString()
        {
            if (para==0) return "";
            String ans="";
            for (String s:var) ans+="*"+s;
            return para+ans;
        }
        boolean equals(Term that)
        {
            if (this.var.size()!=that.var.size()) return false;
            for (int i=0;i<this.var.size();i++)
                if (!this.var.get(i).equals(that.var.get(i))) return false;
            return true;
        }
        int compareTo(Term that)
        {
            if (this.var.size()>that.var.size()) return -1;
            if (this.var.size()<that.var.size()) return 1;
            for (int i=0;i<this.var.size();i++)
            {
                int x=this.var.get(i).compareTo(that.var.get(i));
                if (x!=0) return x;
            }
            return 0;
        }
        Term times(Term that)
        {
            Term pro=new Term(this.para*that.para);
            for (String s:this.var) pro.var.add(new String(s));
            for (String s:that.var) pro.var.add(new String(s));
            Collections.sort(pro.var);
            return pro;
        }
        Term(int x) { para=x; }
        Term(String s) { if (map.containsKey(s)) para=map.get(s); else var.add(s); }
        Term(Term that) { this.para=that.para; this.var=new ArrayList<>(that.var); }
    }
    class Expression 
    {
        List<Term> list=new ArrayList<>(); //Term List
        char oper='+'; // Arithmetic symbol
        Expression(int x) { list.add(new Term(x)); }
        Expression(String s) { list.add(new Term(s)); }
        Expression(List<Term> l) { list=l; }
        Expression times(Expression that)
        {
            List<Term> c=new ArrayList<>();
            for (Term t1:this.list)
                for (Term t2:that.list)
                    c.add(t1.times(t2));
            c=combine(c);
            return new Expression(c);
        }
        Expression plus(Expression that,int sgn)
        {
            List<Term> c=new ArrayList<>();
            for (Term t:this.list) c.add(new Term(t));
            for (Term t:that.list) 
            {
                Term t2=new Term(t);
                t2.para=t2.para*sgn;
                c.add(t2);
            }
            c=combine(c);
            return new Expression(c);
        }
        Expression cal(Expression that)
        {
            if (oper=='+') return plus(that,1);
            if (oper=='-') return plus(that,-1);
            return times(that);
        }
        List<String> toList()
        {
            List<String> ans=new ArrayList<>();
            for (Term t:list) 
            {
                String s=t.toString();
                if (s.length()>0) ans.add(s);
            }
            return ans;
        }
    }  
    List<Term> combine(List<Term> a) //combine the similar terms
    {
        Collections.sort(a,(t1,t2)->(t1.compareTo(t2))); //sort all terms to make similar terms together
        List<Term> c=new ArrayList<>();
        for (Term t:a)
        {
            if (c.size()!=0 && t.equals(c.get(c.size()-1))) c.get(c.size()-1).para+=t.para;
            else c.add(new Term(t));
        }
        return c;
    }
    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        for (int i=0;i<evalvars.length;i++) map.put(evalvars[i],evalints[i]);
        int i=0,l=expression.length();
        Stack<Expression> stack=new Stack<>();
        Stack<Integer> priStack=new Stack<>();
        Expression zero=new Expression(0);
        stack.push(zero);
        priStack.push(0);
        int pri=0;
        while (i<l)
        {
            char ch=expression.charAt(i);
            if (Character.isDigit(ch))
            {
                int num=0;
                while (i<l && Character.isDigit(expression.charAt(i)))
                {
                    num=num*10+(expression.charAt(i)-48);
                    i++;
                }
                stack.add(new Expression(num));
                continue;
            }
            if (Character.isLetter(ch))
            {
                String s="";
                while (i<l && Character.isLetter(expression.charAt(i)))
                {
                    s+=expression.charAt(i);
                    i++;
                }
                stack.add(new Expression(s));
                continue;
            }
            if (ch=='(') pri+=2;
            if (ch==')') pri-=2;
            if (ch=='+' || ch=='-' || ch=='*')
            {
                int nowPri=pri;
                if (ch=='*') nowPri++;
                while (!priStack.isEmpty() && nowPri<=priStack.peek())
                {
                    Expression now=stack.pop(),last=stack.pop();
                    priStack.pop();
                    stack.push(last.cal(now));
                }
                stack.peek().oper=ch;
                priStack.push(nowPri);
            }
            i++;
        }
        while (stack.size()>1)
        {
            Expression now=stack.pop(),last=stack.pop();
            stack.push(last.cal(now));
        }
        return stack.peek().toList();
    }
}
__________________________________________________________________________________________________
sample 40708 kb submission
class Solution {
    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        Map<String, Integer> evalMap = new HashMap();
			for (int i = 0; i < evalvars.length; ++i)
				evalMap.put(evalvars[i], evalints[i]);

			return parse(expression).evaluate(evalMap).toList();
		}

		public Poly make(String expr) {
			Poly ans = new Poly();
			List<String> list = new ArrayList();
			if (Character.isDigit(expr.charAt(0))) {
				ans.update(list, Integer.valueOf(expr));
			} else {
				list.add(expr);
				ans.update(list, 1);
			}
			return ans;
		}

		public Poly combine(Poly left, Poly right, char symbol) {
			if (symbol == '+')
				return left.add(right);
			if (symbol == '-')
				return left.sub(right);
			if (symbol == '*')
				return left.mul(right);
			throw null;
		}

		public Poly parse(String expr) {
			List<Poly> bucket = new ArrayList();
			List<Character> symbols = new ArrayList();
			int i = 0;
			while (i < expr.length()) {
				if (expr.charAt(i) == '(') {
					int bal = 0, j = i;
					for (; j < expr.length(); ++j) {
						if (expr.charAt(j) == '(')
							bal++;
						if (expr.charAt(j) == ')')
							bal--;
						if (bal == 0)
							break;
					}
					bucket.add(parse(expr.substring(i + 1, j)));
					i = j;
				} else if (Character.isLetterOrDigit(expr.charAt(i))) {
					int j = i;
					search: {
						for (; j < expr.length(); ++j)
							if (expr.charAt(j) == ' ') {
								bucket.add(make(expr.substring(i, j)));
								break search;
							}
						bucket.add(make(expr.substring(i)));
					}
					i = j;
				} else if (expr.charAt(i) != ' ') {
					symbols.add(expr.charAt(i));
				}
				i++;
			}

			for (int j = symbols.size() - 1; j >= 0; --j)
				if (symbols.get(j) == '*')
					bucket.set(j, combine(bucket.get(j), bucket.remove(j + 1), symbols.remove(j)));

			if (bucket.isEmpty())
				return new Poly();
			Poly ans = bucket.get(0);
			for (int j = 0; j < symbols.size(); ++j)
				ans = combine(ans, bucket.get(j + 1), symbols.get(j));

			return ans;
    }
    
    static class Poly {
			HashMap<List<String>, Integer> count;

			Poly() {
				count = new HashMap();
			}

			void update(List<String> key, int val) {
				this.count.put(key, this.count.getOrDefault(key, 0) + val);
			}

			Poly add(Poly that) {
				Poly ans = new Poly();
				for (List<String> k : this.count.keySet())
					ans.update(k, this.count.get(k));
				for (List<String> k : that.count.keySet())
					ans.update(k, that.count.get(k));
				return ans;
			}

			Poly sub(Poly that) {
				Poly ans = new Poly();
				for (List<String> k : this.count.keySet())
					ans.update(k, this.count.get(k));
				for (List<String> k : that.count.keySet())
					ans.update(k, -that.count.get(k));
				return ans;
			}

			Poly mul(Poly that) {
				Poly ans = new Poly();
				for (List<String> k1 : this.count.keySet())
					for (List<String> k2 : that.count.keySet()) {
						List<String> kNew = new ArrayList();
						for (String x : k1)
							kNew.add(x);
						for (String x : k2)
							kNew.add(x);
						Collections.sort(kNew);
						ans.update(kNew, this.count.get(k1) * that.count.get(k2));
					}
				return ans;
			}

			Poly evaluate(Map<String, Integer> evalMap) {
				Poly ans = new Poly();
				for (List<String> k : this.count.keySet()) {
					int c = this.count.get(k);
					List<String> free = new ArrayList();
					for (String token : k) {
						if (evalMap.containsKey(token))
							c *= evalMap.get(token);
						else
							free.add(token);
					}
					ans.update(free, c);
				}
				return ans;
			}

			int compareList(List<String> A, List<String> B) {
				int i = 0;
				for (String x : A) {
					String y = B.get(i++);
					if (x.compareTo(y) != 0)
						return x.compareTo(y);
				}
				return 0;
			}

			List<String> toList() {
				List<String> ans = new ArrayList();
				List<List<String>> keys = new ArrayList(this.count.keySet());
				Collections.sort(keys, (a, b) -> a.size() != b.size() ? b.size() - a.size() : compareList(a, b));

				for (List<String> key : keys) {
					int v = this.count.get(key);
					if (v == 0)
						continue;
					StringBuilder word = new StringBuilder();
					word.append("" + v);
					for (String token : key) {
						word.append('*');
						word.append(token);
					}
					ans.add(word.toString());
				}
				return ans;
			}
		}
}