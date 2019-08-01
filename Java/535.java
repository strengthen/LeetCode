__________________________________________________________________________________________________
sample 1 ms submission
public class Codec {

    List<String> list = new ArrayList<>();
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        if (longUrl == null) return longUrl;
        int i = list.size();
        list.add(longUrl);
        StringBuilder res = new StringBuilder();
        while (i > 0) {
            int cur = i % 62;
            if (cur < 10) {
                res.append(cur);
            } else if (cur < 36) {
                res.append((char)('a' + cur - 10));
            } else {
                res.append((char)('A' + cur - 36));
            }
            cur /= 62;
        }
        return res.reverse().toString();
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        if (shortUrl.length() == 0) return list.get(0);
        int index = 0;
        int mul = 1;
        for (int i = shortUrl.length() - 1; i >= 0; i--) {
            int cur = 0;
            char c = shortUrl.charAt(i);
            if (c >= '0' && c <= '9') {
                cur = c - '0';
            } else if (c >= 'a' && c <= 'z') {
                cur = c - 'a' + 10;
            } else {
                cur = c - 'A' + 36;
            }
            index += (mul * cur);
            mul *= 62;
        }
        return list.get(index);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
__________________________________________________________________________________________________
sample 36900 kb submission
public class Codec {
    private static final String DOMAIN = "http://tinyurl.com/";
    // Map to store 64 possible characters.
    private static char[] chars = new char[]
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 
     'C', 'D', 'E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
     '4', '5', '6', '7', '8', '9', '_', '-'};
    // Maps short URL to long URL.
    private Map<String, String> map = new HashMap<>();
    private static int id;

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        String shortUrl = DOMAIN + idToShortUrl(id);
        
        map.put(shortUrl, longUrl);
        return shortUrl;
    }
    
    private String idToShortUrl(long id) {
        StringBuilder shortUrl = new StringBuilder();

        // Convert given id to a base 64 number.
        while (id > 0) {
            shortUrl.append(String.valueOf(chars[(int) (id % 64)]));
            id = id / 64;
        }

        // Reverse shortURL to complete base conversion.
        return shortUrl.reverse().toString();
    }
    
    

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return map.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
__________________________________________________________________________________________________
