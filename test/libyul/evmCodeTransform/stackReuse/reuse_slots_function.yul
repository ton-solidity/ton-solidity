{
    function f() -> x, y, z, t {}
    let a, b, c, d := f() let x1 := 2 let y1 := 3 mstore(x1, a) mstore(y1, c)
}
// ====
// stackOptimization: true
// ----
//     /* "":58:61   */
//   tag_1
//   tag_2
//   jump	// in
// tag_1:
//   pop
//   swap2
//   swap1
//   pop
//     /* "":72:73   */
//   0x02
//   swap1
//     /* "":84:85   */
//   0x03
//   swap2
//     /* "":86:99   */
//   mstore
//     /* "":100:113   */
//   mstore
//   stop
//     /* "":6:35   */
// tag_2:
//     /* "":25:26   */
//   0x00
//     /* "":28:29   */
//   0x00
//     /* "":31:32   */
//   0x00
//     /* "":22:23   */
//   0x00
//   swap4
//     /* "":6:35   */
//   jump	// out
