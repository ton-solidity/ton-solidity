// import web3
// >>> asBytes = int(10).to_bytes(32, byteorder='big')
// >>> int.from_bytes(web3.Web3.keccak(asBytes[:31]), byteorder='big')
// 9948786400348073077032572701554570401043517428989726124163377057770909578447
// >>> int.from_bytes(web3.Web3.keccak(asBytes[:30]), byteorder='big')
// 110945455955148346822663466543669633859020391897956790847617069135813044810108
// >>> int.from_bytes(web3.Web3.keccak(asBytes[:1]), byteorder='big')
// 85131057757245807317576516368191972321038229705283732634690444270750521936266
// >>> int.from_bytes(web3.Web3.keccak(b''), byteorder='big')
// 89477152217924674838424037953991966239322087453347756267410168184682657981552
{
    mstore(0, 10)
    sstore(0, keccak256(0, 31))
    sstore(1, keccak256(0, 30))
    sstore(2, keccak256(0, 1))
    sstore(2, keccak256(0, 0))
}
// ----
// step: loadResolver
//
// {
//     {
//         mstore(0, 10)
//         sstore(0, keccak256(0, 31))
//         sstore(1, keccak256(0, 30))
//         sstore(2, keccak256(0, 1))
//         sstore(2, keccak256(0, 0))
//     }
// }
