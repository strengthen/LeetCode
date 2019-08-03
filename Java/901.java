__________________________________________________________________________________________________
sample 71 ms submission
class StockSpanner {

    private int[] prices;
    private int[] ndays;
    private int size;
    
    public StockSpanner() {
        this.prices = new int[10001];
        this.ndays = new int[10001];

        size = 0;
        prices[size] = 1000000;
        ndays[size] = 1;
    }
    
    
    public int next(int price) {
        int days = 1;
        while (prices[size] <= price) {
            //int prev_price = prices[size];
            int prev_ndays = ndays[size];
            days += prev_ndays;
            size--;
        }
        
        size++;
        prices[size] = price;
        ndays[size] = days;
        
        return days;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
__________________________________________________________________________________________________
sample 64924 kb submission
class StockSpanner {
    private List<Integer> list = new ArrayList<>();
    private List<Integer> prev = new ArrayList<>();

    public int next(int price) {
        list.add(price);
        int i = list.size() - 2;
        while (!prev.isEmpty() && i >= 0 && list.get(i) <= price) i = prev.get(i);
        prev.add(i);
        return list.size() - 1 - i;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
__________________________________________________________________________________________________
