__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, DomainInfo> cmap = new HashMap<>();
        for (String cpdomain : cpdomains) {
            addup(cmap, cpdomain);
        }
        ArrayList<String> result = new ArrayList<>(cmap.size());
        for (Map.Entry<String, DomainInfo> e : cmap.entrySet()) {
            result.add(e.getValue().count + " " + e.getKey()); 
        }
        return result;
    }
    
    void addup(Map<String, DomainInfo> cmap, String cpdomain) {
        int spaceIndex = cpdomain.indexOf(' ');
        int count = Integer.parseInt(cpdomain.substring(0, spaceIndex));
        String domain = cpdomain.substring(spaceIndex + 1);
        addInfo(cmap.get(domain), cmap, count, domain);
    }
    
    DomainInfo addInfo(DomainInfo d, Map<String, DomainInfo> cmap, int count, 
                       String domain) {
        if (d == null) {
            // there is nothing to do if the domain is null too
            if (domain == null) {
                return null;
            }
            final String updomain = getUpDomain(domain);
            d = new DomainInfo(count, addInfo(cmap.get(updomain), cmap, count, updomain));
            cmap.put(domain, d);
        } else {
            d.count += count;
            for (DomainInfo tmp = d.updomain; tmp != null; tmp = tmp.updomain) {
                tmp.count += count;
            }
        }
        return d;
    }
                 
    String getUpDomain(String domain) {
        int dotIndex = domain.indexOf('.');
        if (dotIndex >= 0) {
            return domain.substring(dotIndex + 1);
        }
        return null;
    }
    
    static class DomainInfo {
        int count;
        DomainInfo updomain;
        
        DomainInfo(int count, DomainInfo updomain) {
            this.count = count;
            this.updomain = updomain;
        }
    }
}
__________________________________________________________________________________________________
sample 35976 kb submission
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        final Map<String, Integer> count = new HashMap<>();
        for(String s : cpdomains) {
            String ss[] = s.split(" ");
            int num = Integer.parseInt(ss[0]);
            String domain = ss[1];
            ss = domain.split("\\.");
            count.put(
                domain,
                count.computeIfAbsent(domain, k->0) + num
            );
            int sum = 1;
            for(int i = 0; i < ss.length - 1; i++) {
                sum += ss[i].length() + i;
                String sub = domain.substring(sum);
                count.put(
                    sub,
                    count.computeIfAbsent(sub, k->0) + num
               );
            }
        }
        final List<String> all = new ArrayList<>();
        for(Map.Entry<String, Integer> e : count.entrySet())
            all.add(
                new StringBuilder().append(e.getValue())
                                   .append(" ")
                                   .append(e.getKey())
                                   .toString()
            );
        return all;
    }
}
__________________________________________________________________________________________________
