import matplotlib.pyplot as plt

def bresenham_line(x1, y1, x2, y2):
    result = [(x1, y1)]  # Store the initial point

    dx = x2 - x1
    dy = y2 - y1

    # Check slope to determine which Bresenham's algorithm to use
    if abs(dy) < abs(dx):  # m < 1
        d = 2 * dy - dx  # Initial value of decision parameter
        while x1 < x2:
            if d < 0:
                d += 2 * dy
                x1 += 1
            else:
                d += 2 * (dy - dx)
                x1 += 1
                y1 += 1
            result.append((x1, y1))

    else:  # m > 1
        d = 2 * dx - dy  # Initial value of decision parameter
        while y1 < y2:
            if d < 0:
                d += 2 * dx
                y1 += 1
            else:
                d += 2 * (dx - dy)
                x1 += 1
                y1 += 1
            result.append((x1, y1))

    return result

# Input the initial coordinates
x1, y1 = map(int, input("Enter coordinates of first point : ").split())
x2, y2 = map(int, input("Enter coordinates of second point : ").split())

result = bresenham_line(x1, y1, x2, y2)

# Extract x and y coordinates for plotting
x_values = [point[0] for point in result]
y_values = [point[1] for point in result]

# Plotting the line
plt.plot(x_values, y_values, marker='o')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Bresenham Line Plot')
plt.grid(True)
plt.show()
