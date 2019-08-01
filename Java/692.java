__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    //排名第一的答案，我不信，要试试。
	int index = 0;
	TNode list[];
    public List<String> topKFrequent(String[] words, int k) {
    	List<String> result = new ArrayList<>();
    	TNode root = new TNode();
    	
    	list = new TNode[words.length];
    	
    	
    	for(String word: words) {
    		addWord(root, word);
    	}
    	
    	mergeSort(list,0, index-1);
       /*/ Comparator<TNode> com=new Comparator<TNode>(){
            @Override
            public int compare(TNode o1,TNode o2){
                if(o1==null)
                    if(o2==null)
                        return 0;
                    else
                        return 1;
                else
                    if(o2==null)
                        return -1;
                    else
                        return o1.frequency==o2.frequency?o1.word.compareTo(o2.word):o2.frequency-o1.frequency;
            }
        };
        Arrays.sort(list,com);/*/
    	for(int i = 0; i < k; ++i) {
    		result.add(list[i].word);
    	}
		return result;
    }

	private void mergeSort(TNode[] list, int m, int n) {
		if(m < n) {
			int mid = m + (n-m)/2;
			mergeSort(list, m, mid);
			mergeSort(list, mid+1, n);
			merging(list,m,mid,n);
		}
	}

	private void merging(TNode[] list, int m, int mid, int n) {
		TNode[] temp = new TNode[n-m+1];
		
		int i = m;
		int j = mid+1;
		int k = 0;
		
		while(i <= mid && j <= n) {
			if(list[i].frequency > list[j].frequency) {
				temp[k++] = list[i++];
			}
			else if(list[i].frequency < list[j].frequency) {
				temp[k++] = list[j++];
			}
			else if(compareWords(list[i].word, list[j].word)) {
					temp[k++] = list[i++];
				}
			else {
					temp[k++] = list[j++];
			}
		}
		
		while(i <= mid) {
			temp[k++] = list[i++];
		}
		
		while(j <= n) {
			temp[k++] = list[j++];
		}
		
		k = 0;
		
		for(i = m; i <= n;) {
			list[i++] = temp[k++];
		}
	}

	protected boolean compareWords(String word1, String word2) {
		for(int i = 0; i < word1.length() && i < word2.length(); ++i) {
			if(word1.charAt(i) < word2.charAt(i))
				return true;
			if(word1.charAt(i) > word2.charAt(i))
				return false;
		}
		return word1.length() < word2.length()?true:false;
	}

	private void addWord(TNode root, String word) {
		for(int i = 0; i < word.length(); ++i) {
			if(null == root.next[word.charAt(i)-'a']) {
				root.next[word.charAt(i)-'a'] = new TNode();
			}
			
			root = root.next[word.charAt(i)-'a'];
		}
		
		if(0 == root.frequency) {
			list[index++] = root;
			root.word = word;
		}
		root.frequency++;
	}
	
}


class TNode {
	TNode next[];
	int frequency;
	String word;
	
	public TNode() {
		next = new TNode[26];
		frequency = 0;
	}
	
}
__________________________________________________________________________________________________
sample 35360 kb submission
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        
        Map<String,Integer> map = new HashMap();
        //List<String> res = new ArrayList();
        
        for(String word:words)
        {
            System.out.println(word);
            map.put(word,map.getOrDefault(word,0)+1);
        }
        
        /*
        List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(map.entrySet());
        java.util.Collections.sort(list);
		Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
			public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
				return (o2.getValue() - o1.getValue());
			}
        });
        
        for(int i=0;i<k;i++)
        {
            System.out.println(list.get(i));
            res.add(list.get(i).getKey());
        }
        */
        
        List<String> candidates = new ArrayList(map.keySet());
        Collections.sort(candidates, (w1, w2) -> map.get(w1).equals(map.get(w2)) ?
                w1.compareTo(w2) : map.get(w2) - map.get(w1));

        return candidates.subList(0, k);
        

    }
}
__________________________________________________________________________________________________
