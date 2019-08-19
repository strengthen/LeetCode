__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def validIPAddress(self, IP: str) -> str:
        
        
        def checkIPv4(IP):
            
            IPList = IP.split('.')
            if len(IPList) != 4:
                return "Neither"
            
            for part in IPList:
                if not part:
                    return "Neither"
                if part[0] == '0':
                    if len(part) > 1:
                        return "Neither"
                elif not part.isdigit() or int(part) > 255:
                    return "Neither"
                
            return "IPv4"
        
        def checkIPv6(IP):
            IPList = IP.split(":")
            if len(IPList) != 8:
                return "Neither"
            for part in IPList:
                if not part or len(part) > 4:
                    return "Neither"
    
                for c in part:
                    if not c.isdigit() and (c not in "abcdefABCDEF"):
                        return "Neither"
            
            return "IPv6"
        
                
        if "." in IP:
            return checkIPv4(IP)
        elif ":" in IP:
            return checkIPv6(IP)
        else:
            return "Neither"
__________________________________________________________________________________________________
sample 13024 kb submission
class Solution:
    def __init__(self):
        self.characters = {'a', 'b', 'c', 'd', 'e', 'f', 
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
    
    def _ipv4(self, ip):
        ip = ip.split('.')
        for x in ip:
            if x.startswith('0') and len(x) > 1:
                return "Neither"
            try:
                x_int = int(x)
            except:
                return "Neither"
            if not (x_int >= 0 and x_int <= 255):
                return "Neither"
        return "IPv4"
    
    def _ipv6(self, ip):
        ip = ip.split(':')
        for x in ip:
            if len(x) > 4 or len(x) == 0:
                return "Neither"
            s = {y for y in x if y.lower() not in self.characters}
            if s:
                return "Neither"
        return 'IPv6'

    def validIPAddress(self, IP: str) -> str:
        if len(IP) > 39:
            return "Neither"
        c = collections.Counter(IP)
        if '-' in c:
            return "Neither"
        if '.' in c and c['.'] == 3:
            return self._ipv4(IP)
        elif ':' in c and c[':'] == 7:
            return self._ipv6(IP)
        return "Neither"
__________________________________________________________________________________________________
