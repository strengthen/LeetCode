__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        tempDict = {}
        for i in cpdomains:
            count,domain = i.split(' ')
            if domain not in tempDict:
                tempDict[domain] = int(count)
            else:
                tempDict[domain] += int(count)
            
            subdomain = domain.split('.')[1::]
            temp = ''
            for j in range(len(subdomain)-1, -1, -1):
                if temp == '':
                    temp = subdomain[j]
                else:
                    temp = subdomain[j] + '.' + temp
                if temp not in tempDict:
                    tempDict[temp] = int(count)
                else:
                    tempDict[temp] += int(count)
        result = []
        for k,v in tempDict.items():
            result.append(str(v) + ' ' + k)
        return result
__________________________________________________________________________________________________
sample 13036 kb submission
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        
        dic={}
        for i in cpdomains:
            temp = i.split(" ")
            
            # temp[0] is the count 
            # temp[1] is the domain name 
            
            subdomain = []
            subdomain.append(temp[1])
            a= temp[1]
            b=temp[1]
            for k in range(0,a.count(".")):
                index = b.find(".")
                string = b[index+1:]
                subdomain.append(string)
                b = string
        
            count= int(temp[0])
            for j in subdomain:
                if j in dic:
                    dic[j] = dic[j]+count
                else:
                    dic[j] = count 
        
        

        result = [] 
        for i in range(0,len(dic)):
            key, value = dic.popitem()
            string = str(value)+" " + key
            result.append(string)
        
        return result
__________________________________________________________________________________________________
