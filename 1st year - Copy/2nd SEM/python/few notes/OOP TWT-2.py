class Vehicle():
    def __init__(self,price,gas,color):
        self.price=price
        self.gas=gas
        self.color=color

    def filluptank(self):
        self.gas=100

    def empytytank(self):
        self.gas=0

    def gasleft(self):
        return self.gas

class Car(Vehicle):
    def __init__(self, price, gas, color,speed):
        super().__init__(price, gas, color,speed)   
        self.speed=speed

    def beep(self):
        print('beep!beep!')               

class Truck(Car):
    def __init__(self, price, gas, color,tires):
        super().__init__(price, gas, color)   
        self.tires=tires    

    def beep(self):
        print('honk!honk!')