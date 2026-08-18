class Solution {
    class tuple{
        int row;
        int col;
        int maxEle;
        tuple(int row, int col, int maxEle){
            this.row = row;
            this.col = col;
            this.maxEle = maxEle; //max elevation encountered to reach this cell
        }
    }
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        if(n == 1) return grid[0][0];
        PriorityQueue<tuple> pq = new PriorityQueue<>(
            (a,b) -> a.maxEle - b.maxEle
        );
        int[][] dir = {
            {-1,0}, {1,0}, {0,1}, {0,-1}
        };
        int[][] dist = new int[n][n];  //time required to reach a cell from source
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = (int) 1e9;
            }
        }
        dist[0][0] = grid[0][0]; //source
        pq.offer(new tuple(0,0,grid[0][0]));
        
        while(!pq.isEmpty()){
            tuple curr = pq.poll();
            int row = curr.row;
            int col = curr.col;
            int maxEle = curr.maxEle;

            if(maxEle > dist[row][col]) continue; //pruning

            if(row == n-1 && col == n-1){
                return maxEle;
            }

            for(int[] temp: dir){
                int nr = row + temp[0];
                int nc = col + temp[1];

                if(nr<0 || nr>=n || nc<0 || nc>=n) continue; //skip this for loop iteration

                int candEle = Math.max(maxEle, grid[nr][nc]);
                if(candEle < dist[nr][nc]){
                    dist[nr][nc] = candEle;
                    pq.offer(new tuple(nr, nc, candEle));
                }
            }
        }
        return 1; //to solve compile error for return statement, not executed
    }
}