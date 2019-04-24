__________________________________________________________________________________________________
4ms
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
			return "0";
		string result = "";
		if (numerator < 0 ^ denominator < 0)
			result += "-";
		long n = labs(numerator);
		long d = labs(denominator);
		result += to_string(n / d);
		long r = n % d;
		if (r == 0)
			return result;
		result += ".";
		unordered_map<int, int> last_position;
		while (r != 0) {
			if (r != 0 && last_position.find(r) != last_position.end()) {
				result.insert(last_position[r], "(");
				result += ")";
				return result;
			}
			else {
				last_position[r] = result.size();
			}
			r *= 10;
			result += to_string(r / d);
			r = r % d;
		}
		return result;
	}
};
__________________________________________________________________________________________________
8540 kb
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (!numerator || !denominator)
			return string("0");
		bool minus = (numerator < 0) ^ (denominator < 0);
		long long q = ((long long)numerator) * (minus ? -1 : 1) / denominator;
		long long r = ((long long)numerator) * (minus ? -1 : 1) % denominator;
		vector<long long> vQs;
		vector<int> vRs;
		vQs.push_back(q);
		if (r)
			vRs.push_back(r);
		bool bRecurr = false;
		vector<int>::iterator it;
		while (r)
		{
			r = r * 10;
			q = r / denominator;
			r = r % denominator;

			vQs.push_back(q);
			if (!r)
				break;
			else if ((it = find(vRs.begin(), vRs.end(), r)) != vRs.end())
			{
				bRecurr = true;
				break;
			}

			vRs.push_back(r);
		}
		//
		string ret;
		ret.append(itoa(vQs.front()));
		if (!vRs.empty())
		{
			ret.append(1, '.');
			for (int i = 1; i < vQs.size(); i++)
			{
				if (bRecurr && vRs[i - 1] == *it)
					ret.append(1, '(');
				ret.append(itoa(vQs[i]));
			}

			if (bRecurr)
				ret.append(1, ')');
		}
		if (minus)
			ret = string("-") + ret.c_str();
		return ret;
	}

	char * itoa(long long num)
	{
		static char buffer[32];
		memset(buffer, NULL, sizeof(buffer));

		//
		int i = 0;
		if (num < 0)
		{
			buffer[0] = '-';
			num = num * -1;
			i++;
		}
		do
		{
			buffer[i++] = (num % 10) + '0';
			num = num / 10;
		} while (num);
		// reverse
		int begin = 0, end = i - 1;
		while (begin < end)
		{
			char tmp = buffer[begin];
			buffer[begin] = buffer[end];
			buffer[end] = tmp;
			begin++;
			end--;
		}

		return buffer;
	}
};
__________________________________________________________________________________________________
