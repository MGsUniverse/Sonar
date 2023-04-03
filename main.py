import serial
import turtle


def parse(input):
    input = input.decode("UTF-8").strip()
    measures = input.split(" ")
    output = []
    for i in range(len(measures)):
        t = tuple(measures[i].split(","))
        if len(t) == 2 and len(t[0])>0 and len(t[1])>0:
            output.append(t)
    return output


s = turtle.getscreen()
# t = turtle.Turtle()
turtle.speed(0)
turtle.shape("circle")
turtle.color("red")
turtle.stamp()
turtle.shapesize(0.5, 0.5, 1)

z1baudrate = 115200
z1port = 'COM3'  # set the correct port before run it

z1serial = serial.Serial(port=z1port, baudrate=z1baudrate)
z1serial.timeout = 2  # set read timeout
# print z1serial  # debug serial.
print(z1serial.is_open)  # True for opened
if z1serial.is_open:
    while True:
        size = z1serial.inWaiting()
        # data = z1serial.read(size)
        # time.sleep(0.0005)
        # size = z1serial.inWaiting()
        if size:
            data = z1serial.read(size)
            data = parse(data)
            try:
                # for i in data:
                i = data[-1]
                if int(i[1]) == 179 or int(i[1]) == 0:
                    turtle.clear()
                    turtle.goto(0, 0)
                    turtle.color("red")
                    turtle.shapesize(1, 1, 1)
                    turtle.stamp()
                    turtle.shapesize(0.5, 0.5, 1)

                turtle.setheading(int(i[1]))
                turtle.up()
                turtle.forward(int(i[0]) * 3)
                turtle.color("black")
                turtle.down()
                turtle.stamp()
                turtle.up()
                turtle.color("red")
                turtle.goto(0, 0)
            except Exception as ex:
                pass
        else:
            pass
        # time.sleep(0.0075)
else:
    print('z1serial not open')
# z1serial.close()  # close z1serial if z1serial is open.
