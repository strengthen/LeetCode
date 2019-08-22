__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        addr = set()
        for e in emails:
            i = e.find("@")  
            local  = e[:i]
            domain = e[i:]
            j = local.find("+")
            if j!=-1:
                local=local[:j]
            local=local.replace(".","")
            addr.add(local+domain)
        
        return len(addr)
__________________________________________________________________________________________________
sample 12972 kb submission
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        emails_set = set();
        for email in emails:
            local_name,domain_name = email.split('@');
            local_name = "".join(local_name.split('+')[0].split('.'));
            email = local_name + '@' + domain_name;
            emails_set.add(email)
        return len(emails_set)
__________________________________________________________________________________________________
