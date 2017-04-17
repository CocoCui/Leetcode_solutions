from collections import OrderedDict
class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.dic = OrderedDict()
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.dic:
            val = self.dic[key]
            del self.dic[key]
            self.dic[key] = val
            return val
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.dic:
            del self.dic[key]
        self.dic[key] = value
        if len(self.dic) > self.cap:
            self.dic.popitem(False)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value
