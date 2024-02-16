import matplotlib.pyplot as plt

def draw_line(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    result = [(x1, y1)]
    xinc = float(x1)
    yinc = float(y1)

    # when m==0
    if dx == 0:
        for i in range(y1 + 1, y2):
            result.append((x1, i))
    else:
        m = dy / dx
        if m < 1:
            for i in range(x1 + 1, x2):
                yinc += m
                xinc += 1
                result.append((i, int(round(yinc))))
        elif m > 1:
            for i in range(y1 + 1, y2):
                xinc += 1 / m
                yinc += 1
                result.append((int(round(xinc)), i))
        else:
            for i in range(x1 + 1, x2):
                result.append((i, i))
    result.append((x2, y2))

    return result

# Input the initial coordinate
x1, y1 = map(int, input("Enter coordinates of first point (x1 y1): ").split())
x2, y2 = map(int, input("Enter coordinates of second point (x2 y2): ").split())

result = draw_line(x1, y1, x2, y2)

# Extract x and y coordinates for plotting
x_values = [point[0] for point in result]
y_values = [point[1] for point in result]

# Plotting the line
plt.plot(x_values, y_values, marker='o')
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Line Plot')
plt.grid(True)
plt.show()
