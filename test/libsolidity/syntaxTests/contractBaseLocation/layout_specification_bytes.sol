bytes32 constant b = "bytes";
contract A layout at b[1] {}
// ----
// TypeError 1763: (51-55): Contract storage base location must be in range of type uint256. Current type is bytes1
