class ParkingSystem {
public:
    int slot[3];

    ParkingSystem(int big, int medium, int small) {
        slot[0] = big;
        slot[1] = medium;
        slot[2] = small;
    }
    
    bool addCar(int carType) {
        return slot[carType - 1] && slot[carType - 1]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */