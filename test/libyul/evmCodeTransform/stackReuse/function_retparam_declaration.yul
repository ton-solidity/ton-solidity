{
    function f() -> x { pop(address()) let y := callvalue() }
}
// ====
// stackOptimization: true
// ----
//   stop
//     /* "":6:63   */
// tag_1:
//     /* "":22:23   */
//   0x00
//   swap1
//     /* "":30:39   */
//   address
//     /* "":26:40   */
//   pop
//     /* "":50:61   */
//   callvalue
//     /* "":6:63   */
//   pop
//   jump	// out
