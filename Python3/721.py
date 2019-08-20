__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email_to_name = {}
        graph = collections.defaultdict(set)
        for acc in accounts:
            # each account
            name = acc[0] # e.g. John
            for email in acc[1:]:
                # each email for an account, e.g. john1@gmail.com, john2@gmail.com
                graph[acc[1]].add(email) # draw an edge from the first email to itself and all other emails
                graph[email].add(acc[1])  # draw an edge from email to first account
                email_to_name[email] = name # map from emails to names using the same data structure
        # DFS
        seen = set()
        merged = []
        for email in graph:
            # each email
            if email not in seen:
                seen.add(email)
                stack = [email]
                component = []
                while stack:
                    node = stack.pop()
                    component.append(node)
                    for nei in graph[node]:
                        if nei not in seen:
                            seen.add(nei)
                            stack.append(nei)
                merged.append([email_to_name[email]] + sorted(component))
        return merged
__________________________________________________________________________________________________
sample 17712 kb submission
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        visited = [False] * len(accounts)
        email_acct_map = collections.defaultdict(list)
        
        for idx, acct in enumerate(accounts):
            emails = acct[1:]
            
            for email in emails:
                email_acct_map[email].append(idx)
                
        stack = []
        rslts = []
        
        for idx, acct in enumerate(accounts):
            if visited[idx]:
                continue
                
            stack.append(idx)
            emails = set()
            name = None
            while stack:
                acct_idx_next = stack.pop()
                visited[acct_idx_next] = True
                acct_next = accounts[acct_idx_next]
                name = acct_next[0]
                
                for email in acct_next[1:]:
                    emails.add(email)
                    nbrs = email_acct_map[email]
                    for nbr in nbrs:
                        if not visited[nbr]:
                            stack.append(nbr)
                  
                
            rslts.append([name] + sorted(list(emails)))
            
        return rslts
__________________________________________________________________________________________________
