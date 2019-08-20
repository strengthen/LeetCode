__________________________________________________________________________________________________
sample 4 ms submission
class Codec:

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        return longUrl

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return shortUrl
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
__________________________________________________________________________________________________
sample 8 ms submission
CHOICES = ''.join(
    [chr(ord('0') + i) for i in range(10)] +
    [chr(ord('A') + i) for i in range(26)] +
    [chr(ord('a') + i) for i in range(26)])

INDICES = [0] * 256
for i in range(10):
    INDICES[ord('0') + i] = i
for i in range(26):
    INDICES[ord('A') + i] = 10 + i
    INDICES[ord('a') + i] = 10 + 26 + i


class Codec:
    def __init__(self):
        self.long_urls = []

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.

        :type longUrl: str
        :rtype: str
        """
        index = len(self.long_urls)
        self.long_urls.append(longUrl)

        short = []
        for _ in range(6):
            index, r = divmod(index, 62)
            short.append(CHOICES[r])

        return ''.join(short)

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.

        :type shortUrl: str
        :rtype: str
        """
        index = 0
        power = 1

        for c in shortUrl:
            index += INDICES[ord(c)] * power
            power *= 62

        return self.long_urls[index]
__________________________________________________________________________________________________
sample 12 ms submission
import string
import random

URL_PREFIX = 'http://tinyurl.com/{}'

class Codec:
    urls = {}
    ids = string.ascii_letters + string.digits

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        while True:
            url_id = ''.join(random.choice(self.ids) for _ in range(6))
            if url_id not in self.urls:
                break
        assert len(url_id) == 6
        short_url = '{}{}'.format(URL_PREFIX, url_id)
        self.urls[url_id] = longUrl
        return short_url
        

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        assert URL_PREFIX in shortUrl
        url_id = shortUrl[len(URL_PREFIX):]
        assert len(url_id) == 6 , '{} {}'.format(shortUrl, url_id)
        assert url_id in self.urls, '{} {}'.format(shortUrl, url_id)
        return self.urls[url_id]
        
        
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))