#pragma once

#include <string>

namespace ethdebug::data
{

static std::string const InstructionTypes = {R"_(
{
  "arithmetic": [
    "ADD",
    "MUL",
    "SUB",
    "DIV",
    "SDIV",
    "MOD",
    "SMOD",
    "ADDMOD",
    "MULMOD",
    "EXP",
    "SIGNEXTEND"
  ],
  "logic": [
    "LT",
    "GT",
    "SLT",
    "SGT",
    "EQ",
    "ISZERO",
    "AND",
    "OR",
    "XOR",
    "NOT",
    "BYTE",
    "SHL",
    "SHR",
    "SAR",
    "KECCAK256"
  ],
  "stack": [
    "POP",
    "PUSH0",
    "PUSH1",
    "PUSH2",
    "PUSH3",
    "PUSH4",
    "PUSH5",
    "PUSH6",
    "PUSH7",
    "PUSH8",
    "PUSH9",
    "PUSH10",
    "PUSH11",
    "PUSH12",
    "PUSH13",
    "PUSH14",
    "PUSH15",
    "PUSH16",
    "PUSH17",
    "PUSH18",
    "PUSH19",
    "PUSH20",
    "PUSH21",
    "PUSH22",
    "PUSH23",
    "PUSH24",
    "PUSH25",
    "PUSH26",
    "PUSH27",
    "PUSH28",
    "PUSH29",
    "PUSH30",
    "PUSH31",
    "PUSH32",
    "DUP1",
    "DUP2",
    "DUP3",
    "DUP4",
    "DUP5",
    "DUP6",
    "DUP7",
    "DUP8",
    "DUP9",
    "DUP10",
    "DUP11",
    "DUP12",
    "DUP13",
    "DUP14",
    "DUP15",
    "DUP16",
    "SWAP1",
    "SWAP2",
    "SWAP3",
    "SWAP4",
    "SWAP5",
    "SWAP6",
    "SWAP7",
    "SWAP8",
    "SWAP9",
    "SWAP10",
    "SWAP11",
    "SWAP12",
    "SWAP13",
    "SWAP14",
    "SWAP15",
    "SWAP16"
  ],
  "memory": [
    "MLOAD",
    "MSTORE",
    "MSTORE8",
    "MSIZE",
    "MCOPY",
    "CALLDATALOAD",
    "CALLDATASIZE",
    "CALLDATACOPY",
    "CODESIZE",
    "CODECOPY",
    "EXTCODECOPY",
    "RETURNDATASIZE",
    "RETURNDATACOPY"
  ],
  "storage": [
    "SLOAD",
    "SSTORE"
  ],
  "tstorage": [
    "TLOAD",
    "TSTORE"
  ],
  "control": [
    "STOP",
    "JUMP",
    "JUMPI",
    "PC",
    "JUMPDEST",
    "CREATE",
    "CREATE2",
    "CALL",
    "CALLCODE",
    "DELEGATECALL",
    "STATICCALL",
    "RETURN",
    "REVERT",
    "INVALID",
    "SELFDESTRUCT",
    "ADDRESS",
    "BALANCE",
    "ORIGIN",
    "CALLER",
    "CALLVALUE",
    "BLOCKHASH",
    "COINBASE",
    "TIMESTAMP",
    "NUMBER",
    "DIFFICULTY",
    "PREVRANDAO",
    "GASLIMIT",
    "CHAINID",
    "SELFBALANCE",
    "BASEFEE",
    "BLOBHASH",
    "BLOBBASEFEE",
    "EXTCODESIZE",
    "EXTCODEHASH",
    "GAS",
    "GASPRICE",
    "LOG0",
    "LOG1",
    "LOG2",
    "LOG3",
    "LOG4"
  ]
}
)_"};

static std::string const InstructionInfo = {R"_(
{
  "00": {
    "input": "",
    "output": "",
    "description": "Halts execution"
  },
  "01": {
    "input": "a | b",
    "output": "a + b",
    "description": "Addition operation"
  },
  "02": {
    "input": "a | b",
    "output": "a * b",
    "description": "Multiplication operation"
  },
  "03": {
    "input": "a | b",
    "output": "a - b",
    "description": "Subtraction operation"
  },
  "04": {
    "input": "a | b",
    "output": "a // b",
    "description": "Integer division operation"
  },
  "05": {
    "input": "a | b",
    "output": "a // b",
    "description": "Signed integer division operation (truncated)"
  },
  "06": {
    "input": "a | b",
    "output": "a % b",
    "description": "Modulo remainder operation"
  },
  "07": {
    "input": "a | b",
    "output": "a % b",
    "description": "Signed modulo remainder operation"
  },
  "08": {
    "input": "a | b | N",
    "output": "(a + b) % N",
    "description": "Modulo addition operation"
  },
  "09": {
    "input": "a | b | N",
    "output": "(a * b) % N",
    "description": "Modulo multiplication operation"
  },
  "0a": {
    "input": "a | exponent",
    "output": "a ** exponent",
    "description": "Exponential operation",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "exponent": {
            "type": "number",
            "label": "Input: exponent"
          }
        }
      }
    }
  },
  "0b": {
    "input": "b | x",
    "output": "y",
    "description": "Extend length of two’s complement signed integer"
  },
  "0c": {
    "input": "",
    "output": "",
    "description": ""
  },
  "0d": {
    "input": "",
    "output": "",
    "description": ""
  },
  "0e": {
    "input": "",
    "output": "",
    "description": ""
  },
  "0f": {
    "input": "",
    "output": "",
    "description": ""
  },
  "10": {
    "input": "a | b",
    "output": "a < b",
    "description": "Less-than comparison"
  },
  "11": {
    "input": "a | b",
    "output": "a > b",
    "description": "Greater-than comparison"
  },
  "12": {
    "input": "a | b",
    "output": "a < b",
    "description": "Signed less-than comparison"
  },
  "13": {
    "input": "a | b",
    "output": "a > b",
    "description": "Signed greater-than comparison"
  },
  "14": {
    "input": "a | b",
    "output": "a == b",
    "description": "Equality comparison"
  },
  "15": {
    "input": "a",
    "output": "a == 0",
    "description": "Is-zero comparison"
  },
  "16": {
    "input": "a | b",
    "output": "a & b",
    "description": "Bitwise AND operation"
  },
  "17": {
    "input": "a | b",
    "output": "a \\| b",
    "description": "Bitwise OR operation"
  },
  "18": {
    "input": "a | b",
    "output": "a ^ b",
    "description": "Bitwise XOR operation"
  },
  "19": {
    "input": "a",
    "output": "~a",
    "description": "Bitwise NOT operation"
  },
  "1a": {
    "input": "i | x",
    "output": "y",
    "description": "Retrieve single byte from word"
  },
  "1b": {
    "input": "shift | value",
    "output": "value << shift",
    "description": "Left shift operation"
  },
  "1c": {
    "input": "shift | value",
    "output": "value >> shift",
    "description": "Logical right shift operation"
  },
  "1d": {
    "input": "shift | value",
    "output": "value >> shift",
    "description": "Arithmetic (signed) right shift operation"
  },
  "1e": {
    "input": "",
    "output": "",
    "description": ""
  },
  "1f": {
    "input": "",
    "output": "",
    "description": ""
  },
  "20": {
    "input": "offset | size",
    "output": "hash",
    "description": "Compute Keccak-256 hash",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "21": {
    "input": "",
    "output": "",
    "description": ""
  },
  "22": {
    "input": "",
    "output": "",
    "description": ""
  },
  "23": {
    "input": "",
    "output": "",
    "description": ""
  },
  "24": {
    "input": "",
    "output": "",
    "description": ""
  },
  "25": {
    "input": "",
    "output": "",
    "description": ""
  },
  "26": {
    "input": "",
    "output": "",
    "description": ""
  },
  "27": {
    "input": "",
    "output": "",
    "description": ""
  },
  "28": {
    "input": "",
    "output": "",
    "description": ""
  },
  "29": {
    "input": "",
    "output": "",
    "description": ""
  },
  "2a": {
    "input": "",
    "output": "",
    "description": ""
  },
  "2b": {
    "input": "",
    "output": "",
    "description": ""
  },
  "2c": {
    "input": "",
    "output": "",
    "description": ""
  },
  "2d": {
    "input": "",
    "output": "",
    "description": ""
  },
  "2e": {
    "input": "",
    "output": "",
    "description": ""
  },
  "2f": {
    "input": "",
    "output": "",
    "description": ""
  },
  "30": {
    "input": "",
    "output": "address",
    "description": "Get address of currently executing account"
  },
  "31": {
    "input": "address",
    "output": "balance",
    "description": "Get balance of the given account",
    "dynamicFee": {
      "berlin": {
        "inputs": {
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          }
        }
      }
    }
  },
  "32": {
    "input": "",
    "output": "address",
    "description": "Get execution origination address"
  },
  "33": {
    "input": "",
    "output": "address",
    "description": "Get caller address"
  },
  "34": {
    "input": "",
    "output": "value",
    "description": "Get deposited value by the instruction/transaction responsible for this execution"
  },
  "35": {
    "input": "i",
    "output": "data[i]",
    "description": "Get input data of current environment"
  },
  "36": {
    "input": "",
    "output": "size",
    "description": "Get size of input data in current environment"
  },
  "37": {
    "input": "destOffset | offset | size",
    "output": "",
    "description": "Copy input data in current environment to memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: destOffset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "38": {
    "input": "",
    "output": "size",
    "description": "Get size of code running in current environment"
  },
  "39": {
    "input": "destOffset | offset | size",
    "output": "",
    "description": "Copy code running in current environment to memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: destOffset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "3a": {
    "input": "",
    "output": "price",
    "description": "Get price of gas in current environment"
  },
  "3b": {
    "input": "address",
    "output": "size",
    "description": "Get size of an account’s code",
    "dynamicFee": {
      "berlin": {
        "inputs": {
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          }
        }
      }
    }
  },
  "3c": {
    "input": "address | destOffset | offset | size",
    "output": "",
    "description": "Copy an account’s code to memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: destOffset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      },
      "berlin": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: destOffset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          }
        }
      }
    }
  },
  "3d": {
    "input": "",
    "output": "size",
    "description": "Get size of output data from the previous call from the current environment"
  },
  "3e": {
    "input": "destOffset | offset | size",
    "output": "",
    "description": "Copy output data from the previous call to memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: destOffset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "3f": {
    "input": "address",
    "output": "hash",
    "description": "Get hash of an account’s code",
    "dynamicFee": {
      "berlin": {
        "inputs": {
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          }
        }
      }
    }
  },
  "40": {
    "input": "blockNumber",
    "output": "hash",
    "description": "Get the hash of one of the 256 most recent complete blocks"
  },
  "41": {
    "input": "",
    "output": "address",
    "description": "Get the block’s beneficiary address"
  },
  "42": {
    "input": "",
    "output": "timestamp",
    "description": "Get the block’s timestamp"
  },
  "43": {
    "input": "",
    "output": "blockNumber",
    "description": "Get the block’s number"
  },
  "44": {
    "input": "",
    "output": "difficulty",
    "description": "Get the block’s difficulty"
  },
  "44_merge": {
    "input": "",
    "output": "prevRandao",
    "description": "Get the previous block’s RANDAO mix"
  },
  "45": {
    "input": "",
    "output": "gasLimit",
    "description": "Get the block’s gas limit"
  },
  "46": {
    "input": "",
    "output": "chainId",
    "description": "Get the chain ID"
  },
  "47": {
    "input": "",
    "output": "balance",
    "description": "Get balance of currently executing account"
  },
  "48": {
    "input": "",
    "output": "baseFee",
    "description": "Get the base fee"
  },
  "49": {
    "input": "index",
    "output": "blobVersionedHashesAtIndex",
    "description": "Get versioned hashes"
  },
  "4a": {
    "input": "",
    "output": "blobBaseFee",
    "description": "Returns the value of the blob base-fee of the current block"
  },
  "4b": {
    "input": "",
    "output": "",
    "description": ""
  },
  "4c": {
    "input": "",
    "output": "",
    "description": ""
  },
  "4d": {
    "input": "",
    "output": "",
    "description": ""
  },
  "4e": {
    "input": "",
    "output": "",
    "description": ""
  },
  "4f": {
    "input": "",
    "output": "",
    "description": ""
  },
  "50": {
    "input": "y",
    "output": "",
    "description": "Remove item from stack"
  },
  "51": {
    "input": "offset",
    "output": "value",
    "description": "Load word from memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "52": {
    "input": "offset | value",
    "output": "",
    "description": "Save word to memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "53": {
    "input": "offset | value",
    "output": "",
    "description": "Save byte to memory",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "54": {
    "input": "key",
    "output": "value",
    "description": "Load word from storage",
    "dynamicFee": {
      "berlin": {
        "inputs": {
          "cold": {
            "type": "boolean",
            "label": "State: 'key' is cold?"
          }
        }
      }
    }
  },
  "55": {
    "input": "key | value",
    "output": "",
    "description": "Save word to storage",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "newValue": {
            "type": "number",
            "label": "Input: value"
          },
          "currentValue": {
            "type": "number",
            "label": "State: current value in storage"
          }
        }
      },
      "constantinople": {
        "inputs": {
          "newValue": {
            "type": "number",
            "label": "Input: value"
          },
          "currentValue": {
            "type": "number",
            "label": "State: current value in storage"
          },
          "originalValue": {
            "type": "number",
            "label": "State: original value before the current transaction"
          }
        }
      },
      "petersburg": {
        "inputs": {
          "newValue": {
            "type": "number",
            "label": "Input: value"
          },
          "currentValue": {
            "type": "number",
            "label": "State: current value in storage"
          }
        }
      },
      "istanbul": {
        "inputs": {
          "newValue": {
            "type": "number",
            "label": "Input: value"
          },
          "currentValue": {
            "type": "number",
            "label": "State: current value in storage"
          },
          "originalValue": {
            "type": "number",
            "label": "State: original value before the current transaction"
          }
        }
      },
      "berlin": {
        "inputs": {
          "newValue": {
            "type": "number",
            "label": "Input: value"
          },
          "currentValue": {
            "type": "number",
            "label": "State: current value in storage"
          },
          "originalValue": {
            "type": "number",
            "label": "State: original value before the current transaction"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'key' is cold?"
          }
        }
      }
    }
  },
  "56": {
    "input": "counter",
    "output": "",
    "description": "Alter the program counter"
  },
  "57": {
    "input": "counter | b",
    "output": "",
    "description": "Conditionally alter the program counter"
  },
  "58": {
    "input": "",
    "output": "counter",
    "description": "Get the value of the program counter prior to the increment corresponding to this instruction"
  },
  "59": {
    "input": "",
    "output": "size",
    "description": "Get the size of active memory in bytes"
  },
  "5a": {
    "input": "",
    "output": "gas",
    "description": "Get the amount of available gas, including the corresponding reduction for the cost of this instruction"
  },
  "5b": {
    "input": "",
    "output": "",
    "description": "Mark a valid destination for jumps"
  },
  "5c": {
    "input": "key",
    "output": "value",
    "description": "Load word from transient storage"
  },
  "5d": {
    "input": "key | value",
    "output": "",
    "description": "Save word to transient storage"
  },
  "5e": {
    "input": "destOffset | offset | size",
    "output": "",
    "description": "Copy memory areas",
    "dynamicFee": {
      "cancun": {
        "inputs": {
          "destOffset": {
            "type": "number",
            "label": "Input: destination offset"
          },
          "offset": {
            "type": "number",
            "label": "Input: input offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "5f": {
    "input": "",
    "output": "0",
    "description": "Place value 0 on stack"
  },
  "60": {
    "input": "",
    "output": "value",
    "description": "Place 1 byte item on stack"
  },
  "61": {
    "input": "",
    "output": "value",
    "description": "Place 2 byte item on stack"
  },
  "62": {
    "input": "",
    "output": "value",
    "description": "Place 3 byte item on stack"
  },
  "63": {
    "input": "",
    "output": "value",
    "description": "Place 4 byte item on stack"
  },
  "64": {
    "input": "",
    "output": "value",
    "description": "Place 5 byte item on stack"
  },
  "65": {
    "input": "",
    "output": "value",
    "description": "Place 6 byte item on stack"
  },
  "66": {
    "input": "",
    "output": "value",
    "description": "Place 7 byte item on stack"
  },
  "67": {
    "input": "",
    "output": "value",
    "description": "Place 8 byte item on stack"
  },
  "68": {
    "input": "",
    "output": "value",
    "description": "Place 9 byte item on stack"
  },
  "69": {
    "input": "",
    "output": "value",
    "description": "Place 10 byte item on stack"
  },
  "6a": {
    "input": "",
    "output": "value",
    "description": "Place 11 byte item on stack"
  },
  "6b": {
    "input": "",
    "output": "value",
    "description": "Place 12 byte item on stack"
  },
  "6c": {
    "input": "",
    "output": "value",
    "description": "Place 13 byte item on stack"
  },
  "6d": {
    "input": "",
    "output": "value",
    "description": "Place 14 byte item on stack"
  },
  "6e": {
    "input": "",
    "output": "value",
    "description": "Place 15 byte item on stack"
  },
  "6f": {
    "input": "",
    "output": "value",
    "description": "Place 16 byte item on stack"
  },
  "70": {
    "input": "",
    "output": "value",
    "description": "Place 17 byte item on stack"
  },
  "71": {
    "input": "",
    "output": "value",
    "description": "Place 18 byte item on stack"
  },
  "72": {
    "input": "",
    "output": "value",
    "description": "Place 19 byte item on stack"
  },
  "73": {
    "input": "",
    "output": "value",
    "description": "Place 20 byte item on stack"
  },
  "74": {
    "input": "",
    "output": "value",
    "description": "Place 21 byte item on stack"
  },
  "75": {
    "input": "",
    "output": "value",
    "description": "Place 22 byte item on stack"
  },
  "76": {
    "input": "",
    "output": "value",
    "description": "Place 23 byte item on stack"
  },
  "77": {
    "input": "",
    "output": "value",
    "description": "Place 24 byte item on stack"
  },
  "78": {
    "input": "",
    "output": "value",
    "description": "Place 25 byte item on stack"
  },
  "79": {
    "input": "",
    "output": "value",
    "description": "Place 26 byte item on stack"
  },
  "7a": {
    "input": "",
    "output": "value",
    "description": "Place 27 byte item on stack"
  },
  "7b": {
    "input": "",
    "output": "value",
    "description": "Place 28 byte item on stack"
  },
  "7c": {
    "input": "",
    "output": "value",
    "description": "Place 29 byte item on stack"
  },
  "7d": {
    "input": "",
    "output": "value",
    "description": "Place 30 byte item on stack"
  },
  "7e": {
    "input": "",
    "output": "value",
    "description": "Place 31 byte item on stack"
  },
  "7f": {
    "input": "",
    "output": "value",
    "description": "Place 32 byte (full word) item on stack"
  },
  "80": {
    "input": "value",
    "output": "value | value",
    "description": "Duplicate 1st stack item"
  },
  "81": {
    "input": "a | b",
    "output": "b | a | b",
    "description": "Duplicate 2nd stack item"
  },
  "82": {
    "input": "a | b | c",
    "output": "c | a | b | c",
    "description": "Duplicate 3rd stack item"
  },
  "83": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 4th stack item"
  },
  "84": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 5th stack item"
  },
  "85": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 6th stack item"
  },
  "86": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 7th stack item"
  },
  "87": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 8th stack item"
  },
  "88": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 9th stack item"
  },
  "89": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 10th stack item"
  },
  "8a": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 11th stack item"
  },
  "8b": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 12th stack item"
  },
  "8c": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 13th stack item"
  },
  "8d": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 14th stack item"
  },
  "8e": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 15th stack item"
  },
  "8f": {
    "input": "... | value",
    "output": "value | ... | value",
    "description": "Duplicate 16th stack item"
  },
  "90": {
    "input": "a | b",
    "output": "b | a",
    "description": "Exchange 1st and 2nd stack items"
  },
  "91": {
    "input": "a | b | c",
    "output": "c | b | a",
    "description": "Exchange 1st and 3rd stack items"
  },
  "92": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 4th stack items"
  },
  "93": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 5th stack items"
  },
  "94": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 6th stack items"
  },
  "95": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 7th stack items"
  },
  "96": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 8th stack items"
  },
  "97": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 9th stack items"
  },
  "98": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 10th stack items"
  },
  "99": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 11th stack items"
  },
  "9a": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 12th stack items"
  },
  "9b": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 13th stack items"
  },
  "9c": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 14th stack items"
  },
  "9d": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 15th stack items"
  },
  "9e": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 16th stack items"
  },
  "9f": {
    "input": "a | ... | b",
    "output": "b | ... | a",
    "description": "Exchange 1st and 17th stack items"
  },
  "a0": {
    "input": "offset | size",
    "output": "",
    "description": "Append log record with no topics",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "a1": {
    "input": "offset | size | topic",
    "output": "",
    "description": "Append log record with one topic",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "a2": {
    "input": "offset | size | topic1 | topic2",
    "output": "",
    "description": "Append log record with two topics",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "a3": {
    "input": "offset | size | topic1 | topic2 | topic3",
    "output": "",
    "description": "Append log record with three topics",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "a4": {
    "input": "offset | size | topic1 | topic2 | topic3 | topic4",
    "output": "",
    "description": "Append log record with four topics",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "a5": {
    "input": "",
    "output": "",
    "description": ""
  },
  "a6": {
    "input": "",
    "output": "",
    "description": ""
  },
  "a7": {
    "input": "",
    "output": "",
    "description": ""
  },
  "a8": {
    "input": "",
    "output": "",
    "description": ""
  },
  "a9": {
    "input": "",
    "output": "",
    "description": ""
  },
  "aa": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ab": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ac": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ad": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ae": {
    "input": "",
    "output": "",
    "description": ""
  },
  "af": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b0": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b1": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b2": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b3": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b4": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b5": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b6": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b7": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b8": {
    "input": "",
    "output": "",
    "description": ""
  },
  "b9": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ba": {
    "input": "",
    "output": "",
    "description": ""
  },
  "bb": {
    "input": "",
    "output": "",
    "description": ""
  },
  "bc": {
    "input": "",
    "output": "",
    "description": ""
  },
  "bd": {
    "input": "",
    "output": "",
    "description": ""
  },
  "be": {
    "input": "",
    "output": "",
    "description": ""
  },
  "bf": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c0": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c1": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c2": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c3": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c4": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c5": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c6": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c7": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c8": {
    "input": "",
    "output": "",
    "description": ""
  },
  "c9": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ca": {
    "input": "",
    "output": "",
    "description": ""
  },
  "cb": {
    "input": "",
    "output": "",
    "description": ""
  },
  "cc": {
    "input": "",
    "output": "",
    "description": ""
  },
  "cd": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ce": {
    "input": "",
    "output": "",
    "description": ""
  },
  "cf": {
    "input": "",
    "output": "",
    "description": ""
  },
  "d0": {
    "input": "offset",
    "output": "data",
    "description": "Load 32-byte word from data section of EOF container to the stack"
  },
  "d1": {
    "input": "",
    "output": "data",
    "description": "Load 32-byte word from data section of EOF container at given offset to the stack"
  },
  "d2": {
    "input": "",
    "output": "size",
    "description": "Push data section size to the stack"
  },
  "d3": {
    "input": "mem_offset | offset | size",
    "output": "",
    "description": "Copy a segment of data section to memory",
    "dynamicFee": {
      "EOF": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: memory offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "d4": {
    "input": "",
    "output": "",
    "description": ""
  },
  "d5": {
    "input": "",
    "output": "",
    "description": ""
  },
  "d6": {
    "input": "",
    "output": "",
    "description": ""
  },
  "d7": {
    "input": "",
    "output": "",
    "description": ""
  },
  "d8": {
    "input": "",
    "output": "",
    "description": ""
  },
  "d9": {
    "input": "",
    "output": "",
    "description": ""
  },
  "da": {
    "input": "",
    "output": "",
    "description": ""
  },
  "db": {
    "input": "",
    "output": "",
    "description": ""
  },
  "dc": {
    "input": "",
    "output": "",
    "description": ""
  },
  "dd": {
    "input": "",
    "output": "",
    "description": ""
  },
  "de": {
    "input": "",
    "output": "",
    "description": ""
  },
  "df": {
    "input": "",
    "output": "",
    "description": ""
  },
  "e0": {
    "input": "",
    "output": "",
    "description": "Alter the program counter to relative offset"
  },
  "e1": {
    "input": "condition",
    "output": "",
    "description": "Conditionally alter the program counter to relative offset"
  },
  "e2": {
    "input": "case",
    "output": "",
    "description": "Alter the program counter to a relative offset in jump table"
  },
  "e3": {
    "input": "",
    "output": "",
    "description": "Call into a function"
  },
  "e4": {
    "input": "",
    "output": "",
    "description": "Return from a function"
  },
  "e5": {
    "input": "",
    "output": "",
    "description": "Chaining function calls without adding a new return stack frame"
  },
  "e6": {
    "input": "",
    "output": "",
    "description": "Duplicate the stack item at the top of the stack"
  },
  "e7": {
    "input": "",
    "output": "",
    "description": "Swap the stack item with the top stack item"
  },
  "e8": {
    "input": "",
    "output": "",
    "description": "Swap between the first and second nibbles of the stack item"
  },
  "e9": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ea": {
    "input": "",
    "output": "",
    "description": ""
  },
  "eb": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ec": {
    "input": "value | salt | input_offset | input_size",
    "output": "address",
    "description": "Create a contract using EOF container at given index",
    "dynamicFee": {
      "EOF": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "containerSize": {
            "type": "number",
            "label": "State: container size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated deployment execution cost"
          },
          "deployedSize": {
            "type": "number",
            "label": "Estimated deployed code size in bytes"
          }
        }
      }
    }
  },
  "ed": {
    "input": "",
    "output": "",
    "description": ""
  },
  "ee": {
    "input": "aux_data_offset | aux_data_size",
    "output": "",
    "description": "Deploy container to an address",
    "dynamicFee": {
      "EOF": {
        "inputs": {
          "auxDataOffset": {
            "type": "number",
            "label": "Input: auxiliary data offset"
          },
          "auxDataSize": {
            "type": "number",
            "label": "Input: auxiliary data size in bytes"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "ef": {
    "input": "",
    "output": "",
    "description": ""
  },
  "f0": {
    "input": "value | offset | size",
    "output": "address",
    "description": "Create a new account with associated code",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated deployment execution cost"
          },
          "deployedSize": {
            "type": "number",
            "label": "Estimated deployed code size in bytes"
          }
        }
      }
    }
  },
  "f1": {
    "input": "gas | address | value | argsOffset | argsSize | retOffset | retSize",
    "output": "success",
    "description": "Message-call into an account",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "value": {
            "type": "number",
            "label": "Input: value"
          },
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: Current memory size"
          },
          "empty": {
            "type": "boolean",
            "label": "State: is the called account new?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      },
      "spuriousDragon": {
        "inputs": {
          "value": {
            "type": "number",
            "label": "Input: value"
          },
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "empty": {
            "type": "boolean",
            "label": "State: is the called account empty?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      },
      "berlin": {
        "inputs": {
          "value": {
            "type": "number",
            "label": "Input: value"
          },
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          },
          "empty": {
            "type": "boolean",
            "label": "State: is the called account empty?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "f2": {
    "input": "gas | address | value | argsOffset | argsSize | retOffset | retSize",
    "output": "success",
    "description": "Message-call into this account with alternative account’s code",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "value": {
            "type": "number",
            "label": "Input: value"
          },
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      },
      "berlin": {
        "inputs": {
          "value": {
            "type": "number",
            "label": "Input: value"
          },
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "f3": {
    "input": "offset | size",
    "output": "",
    "description": "Halt execution returning output data",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "f4": {
    "input": "gas | address | argsOffset | argsSize | retOffset | retSize",
    "output": "success",
    "description": "Message-call into this account with an alternative account’s code, but persisting the current values for sender and value",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      },
      "berlin": {
        "inputs": {
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "f5": {
    "input": "value | offset | size | salt",
    "output": "address",
    "description": "Create a new account with associated code at a predictable address",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated deployment execution cost"
          },
          "deployedSize": {
            "type": "number",
            "label": "Estimated deployed code size in bytes"
          }
        }
      }
    }
  },
  "f6": {
    "input": "",
    "output": "",
    "description": ""
  },
  "f7": {
    "input": "offset",
    "output": "data",
    "description": "Push 32-byte word from the return data at offset onto the stack"
  },
  "f8": {
    "input": "target_address | input_offset | input_size | value",
    "output": "status",
    "description": "Drop-in replacement for CALL instruction",
    "dynamicFee": {
      "EOF": {
        "inputs": {
          "value": {
            "type": "number",
            "label": "Input: value"
          },
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'targetAddress' is cold?"
          },
          "empty": {
            "type": "boolean",
            "label": "State: is the called account empty?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "f9": {
    "input": "target_address | input_offset | input_size",
    "output": "status",
    "description": "Drop-in replacement for DELEGATECALL instruction",
    "dynamicFee": {
      "EOF": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'targetAddress' is cold?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "fa": {
    "input": "gas | address | argsOffset | argsSize | retOffset | retSize",
    "output": "success",
    "description": "Static message-call into an account",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      },
      "berlin": {
        "inputs": {
          "argsOffset": {
            "type": "number",
            "label": "Input: argsOffset"
          },
          "argsSize": {
            "type": "number",
            "label": "Input: argsSize"
          },
          "retOffset": {
            "type": "number",
            "label": "Input: retOffset"
          },
          "retSize": {
            "type": "number",
            "label": "Input: retSize"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "fb": {
    "input": "target_address | input_offset | input_size",
    "output": "status",
    "description": "Drop-in replacement for STATICCALL instruction",
    "dynamicFee": {
      "EOF": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'targetAddress' is cold?"
          },
          "executionCost": {
            "type": "number",
            "label": "Estimated execution cost"
          }
        }
      }
    }
  },
  "fc": {
    "input": "",
    "output": "",
    "description": ""
  },
  "fd": {
    "input": "offset | size",
    "output": "",
    "description": "Halt execution reverting state changes but returning data and remaining gas",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "offset": {
            "type": "number",
            "label": "Input: offset"
          },
          "size": {
            "type": "number",
            "label": "Input: size"
          },
          "memorySize": {
            "type": "number",
            "label": "State: current memory size"
          }
        }
      }
    }
  },
  "fe": {
    "input": "",
    "output": "",
    "description": "Designated invalid instruction",
    "dynamicFee": {
      "homestead": {
        "inputs": {
          "remaining": {
            "type": "number",
            "label": "State: remaining gas in the current context"
          }
        }
      }
    }
  },
  "ff": {
    "input": "address",
    "output": "",
    "description": "Halt execution and register account for later deletion or send all Ether to address (post-Cancun)",
    "dynamicFee": {
      "homestead": {},
      "tangerineWhistle": {
        "inputs": {
          "empty": {
            "type": "boolean",
            "label": "State: is the beneficiary account new?"
          }
        }
      },
      "spuriousDragon": {
        "inputs": {
          "hasNoBalance": {
            "type": "boolean",
            "label": "State: is the current account balance empty?"
          },
          "empty": {
            "type": "boolean",
            "label": "State: is the beneficiary account empty?"
          }
        }
      },
      "berlin": {
        "inputs": {
          "hasNoBalance": {
            "type": "boolean",
            "label": "State: is the current account balance empty?"
          },
          "empty": {
            "type": "boolean",
            "label": "State: is the beneficiary account empty?"
          },
          "cold": {
            "type": "boolean",
            "label": "State: 'address' is cold?"
          }
        }
      }
    }
  }
}
)_"};

} // namespace ethdebug::data
