contract C layout at 7 {
    uint public x;
    int8 public y;
    uint32 public z;

    constructor(uint _x, int8 _y, uint32 _z) {
        x = _x + 1;
        y = _y + 2;
        z = _z + 3;
    }

}
// ====
// EVMVersion: >=cancun
// compileViaYul: true
// ----
// constructor(): 1, 2, 3
// x() -> 2
// y() -> 4
// z() -> 6
