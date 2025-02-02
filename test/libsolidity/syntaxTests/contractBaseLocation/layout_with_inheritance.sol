contract A { }
contract B { }
contract C is A, B layout at 0x1234 { }
contract D layout at 0xABCD is A, B { }
// ----
// TypeError 2031: (70-109): Conflicting storage layout specifications:Storage layout for base contract 'A' was also specified by another contract which derives from it.
// TypeError 2031: (70-109): Conflicting storage layout specifications:Storage layout for base contract 'B' was also specified by another contract which derives from it.
