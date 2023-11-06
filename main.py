count = 0
length = 42


def simulateBall(Time):
    global count, length
    count = count+1
    if(Time+1.125<=length):
        simulateBall(Time+1.125)
    if(Time+3.225<=length):
        simulateBall(Time+3.225)
    if(Time+5.175<=length):
        simulateBall(Time+5.175)
    if(Time+6.975<=length):
        simulateBall(Time+6.975)
    if(Time+8.625<=length):
        simulateBall(Time+8.625)
    if(Time+10.125<=length):
        simulateBall(Time+10.125)
    if(Time+11.475<=length):
        simulateBall(Time+11.475)
    if(Time+12.675<=length):
        simulateBall(Time+12.675)
    if(Time+13.725<=length):
        simulateBall(Time+13.725)
    if(Time+14.625<=length):
        simulateBall(Time+14.625)
    if(Time+15.375<=length):
        simulateBall(Time+15.375)
    if(Time+15.975<=length):
        simulateBall(Time+15.975)
    if(Time+16.425<=length):
        simulateBall(Time+16.425)
    if(Time+16.725<=length):
        simulateBall(Time+16.725)
    if(Time+16.875<=length):
        simulateBall(Time+16.875)

def main():
    global count
    simulateBall(0)
    print(f"Total balls after", length, "seconds:", count)

main()