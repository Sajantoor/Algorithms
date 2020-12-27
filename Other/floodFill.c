const int WHITE = 0;
const int RED = 1;

void flood_fill(int N, int ar[N][N], int x, int y) {
  // boundary conditions
  if (x < 0 || x >= N || y < 0 || y >= N)
    return;
  
  // point not white condition
  if (ar[x][y] != WHITE)
    return;

  // set the point to be red
  ar[x][y] = RED;

  //make 4 recursive calls
  flood_fill(N, ar, x-1, y); 
  flood_fill(N, ar, x + 1, y); 
  flood_fill(N, ar, x, y - 1); 
  flood_fill(N, ar, x, y + 1); 
}