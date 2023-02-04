class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
      nb_rows = len(matrix)
      nb_cols = len(matrix[0])
      grid = [[0] * (nb_cols+1)  for i in range(nb_rows+1)]


      maxi = 0
      for r in range(nb_rows):
        for c in range(nb_cols):
          if matrix[r][c] == '1':
            tmp = min(grid[r][c], grid[r][c+1], grid[r+1][c]) + 1
            grid[r+1][c+1] = tmp
            maxi = max(maxi, tmp, 1)
      return maxi*maxi
