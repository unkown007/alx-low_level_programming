#!/usr/bin/python3

def square_perimeter(grid, x=0, y=0):
		p = 0
		if (x - 1) < 0 or grid[x - 1][y] == 0:
				p = p + 1;
		if (x + 1) >= len(grid) or grid[x + 1][y] == 0:
				p = p + 1
		if (y - 1) < 0 or grid[x][y - 1] == 0:
				p = p + 1
		if (y + 1) >= len(grid[x]) or grid[x][y + 1] == 0:
				p = p + 1
		return (p)

def island_perimeter(grid):
		perimeter = 0
		for x in range(len(grid)):
				for y in range(len(grid[x])):
						if grid[x][y]:
								aux = square_perimeter(grid, x, y)
								perimeter = perimeter + aux
		return perimeter
