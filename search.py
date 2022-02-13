import os

def load_all_files(base):
    fdict = {}
    for path, ds, fs in os.walk(base):
        for f in fs:
            idx = f.split('_')[0]
            fdict[idx] = os.path.join(path, f)
    return fdict

def user_interface(files):
    while (1):
        raw_in = input("Enter the index of the problem:")
        if raw_in == "q" or raw_in == "Q" or raw_in == "quit":
            print("See you")
            break
        if (not raw_in.isdigit()) or len(raw_in) > 4:
            print("ERROR: Invalid input")
            continue
        for i in range(4 - len(raw_in)):
            raw_in = "0" + raw_in
        
        try:
            print(files[raw_in])
        except:
            print("Sorry, not found problem {}".format(raw_in))

if __name__ == '__main__':
    files = load_all_files("./")
    user_interface(files)