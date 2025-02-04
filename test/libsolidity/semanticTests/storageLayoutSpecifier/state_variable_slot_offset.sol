contract C layout at 7 {
    int8 x;
    int32 y;
    uint256 z;

    function f() public returns(uint s, uint o) {
        assembly {
            s := x.slot
            o := x.offset
        }
    }
    function g() public returns(uint s, uint o) {
        assembly {
            s := y.slot
            o := y.offset
        }
    }
    function h() public returns(uint s, uint o) {
        assembly {
            s := z.slot
            o := z.offset
        }
    }
}
// ====
// EVMVersion: >=cancun
// compileViaYul: true
// ----
// f() -> 7, 0
// g() -> 7, 1
// h() -> 8, 0
