import os

if __name__ == "__main__":
    DIR = ['easy','medium','hard']

    num_solved = [len(next(os.walk(d))[2])-1 for d in DIR]
    print("Total solved: {}".format(sum(num_solved)))
    for i in range(len(DIR)):
        print("{}: {}".format(DIR[i],num_solved[i]))
