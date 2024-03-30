from time import *
import sys
import random

hasTarget=False
ip = ""
name = ""
password = ""

n = ["Simon", "Thomas", "Valérie", "Samuel", "Lucien", "Élodie", "Sébastien", "Annika"]
pw = ["123456789", "123", "999", "P@ssw0rd", "H3ll0", "Mde5eHs@", "XXX"]

def set_ip():
    ip = random.randint(0, 255) + "." + random.randint(0, 255) + "." + random.randint(0, 255) + "." + random.randint(0, 255) + "."

print("Starting hack")
sleep(1)

def func():
    global hasTarget
    global ip
    global name
    global password

    function = input("func>")

    if function == "device.destroy" and hasTarget:
        print("Destroying device")
        sleep(1)
        print("Device destroyed, exit in 10 seconds")
        sleep(10)
    elif function == "device.shut_down" and hasTarget:
        print("Device shutting down")
        sleep(1)
        print("Device off, exit in 10 seconds")
        sleep(10)
    elif function == "get.password" and hasTarget:
        if password == "":
            password = random.choice(pw)
        print("Password : " + password)
        print("")

        func()
    elif function == "get.name" and hasTarget:
        if name == "":
            name = random.choice(n)
        print("Name : " + name)
        print("")

        func()
    elif function == "get.ip" and hasTarget:
        if ip == "":
            set_ip()
        print("IP : " + ip)
        print("")

        func()
    elif function == "set.user":
        name = random.choice(n);

    elif function == "app.start" and hasTarget:
        app = input("Choose application : ")
        print("Searching " + app)
        sleep(1)
        print(app + "found")
        print("")

        print("Starting " + app, end=" ")
        RotatingLoadingBar(0.1, 10)

        print(app + " started")
        print("")

        func()
    elif function == "app.install" and hasTarget:
        app = input("Choose application : ")
        print("Searching " + app)
        sleep(1)
        print(app + " found")
        print("")

        print("Downloading " + app, end=" ")
        ProgressLoadingBar(0.5, 5)

        print("Installing " + app, end =" ")
        RotatingLoadingBar(0.1, 15)

        print(app + " installed")
        print("")

        func()
    elif function == "app.uninstall" and hasTarget:
        app = input("Choose application : ")
        print("Searching " + app)
        sleep(1)
        print(app + " found")
        print("")

        print("Uninstalling " + app, end=" ")
        RotatingLoadingBar(0.1, 15)

        print(app + " uninstalled")
        print("")

        func()
    elif function == "app.find" and hasTarget:
        app = input("Choose application : ")
        print("Searching " + app)
        sleep(1)
        print(app + " found")
        print("Path : C:/Program/" + app)
        print("")

        func()
    elif function == "exit":
        quit()
    else:
        print("Function not found, type help for the functions or set a target with set.target")
        func()

func()