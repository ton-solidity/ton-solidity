{
	function g_(x) -> z_ {
		if calldataload(1) { z_ := g_(x) }
		sstore(z_, calldataload(add(x, 1)))
	}
	function datasize_(x) -> linkersymbol_ {
		if calldataload(0) { linkersymbol_ := datasize_(x) }
		sstore(linkersymbol_, calldataload(linkersymbol_))
	}
	let dataoffset_ := datasize_(7)
	let x_ := g_(9)
	sstore(dataoffset_, x_)
}
// ----
// step: fullSuite
//
// {
//     {
//         let dataoffset_ := datasize_(7)
//         sstore(dataoffset_, g_(9))
//     }
//     function g_(x) -> z_
//     {
//         if calldataload(1) { z_ := g_(x) }
//         sstore(z_, calldataload(add(x, 1)))
//     }
//     function datasize_(x_1) -> linkersymbol_
//     {
//         if calldataload(0)
//         {
//             linkersymbol_ := datasize_(x_1)
//         }
//         sstore(linkersymbol_, calldataload(linkersymbol_))
//     }
// }
