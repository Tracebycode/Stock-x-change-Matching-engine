# Stock Exchange Matching Engine

A high-performance C++ implementation of a financial order matching engine that simulates stock exchange trading operations. This system efficiently matches buy and sell orders based on price and timestamp priority.

## Table of Contents

- [Stock Exchange Matching Engine](#stock-exchange-matching-engine)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Features](#features)
  - [Architecture](#architecture)
    - [Core Components](#core-components)
    - [Key Classes](#key-classes)
  - [Project Structure](#project-structure)
  - [Prerequisites](#prerequisites)
    - [Verify Installation](#verify-installation)
  - [Building](#building)
    - [1. Clone and Navigate](#1-clone-and-navigate)
    - [2. Create Build Directory](#2-create-build-directory)
    - [3. Generate Build Files](#3-generate-build-files)
    - [4. Compile](#4-compile)
    - [5. Run](#5-run)
  - [Usage](#usage)
    - [Basic Example](#basic-example)
  - [How It Works](#how-it-works)
    - [1. Order Submission](#1-order-submission)
    - [2. Order Book Maintenance](#2-order-book-maintenance)
    - [3. Order Matching](#3-order-matching)
  - [Order Matching Algorithm](#order-matching-algorithm)
  - [Example](#example)
  - [Testing](#testing)
  - [Contributing](#contributing)
    - [Areas for Contribution](#areas-for-contribution)
  - [Future Enhancements](#future-enhancements)
  - [License](#license)

## Overview

The Stock Exchange Matching Engine is a financial trading system that:
- Accepts buy and sell orders for multiple stock symbols
- Maintains separate order books for buy and sell orders
- Automatically matches orders when conditions are met
- Executes trades at fair market prices
- Processes orders in real-time with priority-based matching

This is an ideal foundation for learning about exchange engines, algorithmic trading, or building more advanced trading systems.

## Features

✅ **Order Management** - Add, track, and manage buy/sell orders  
✅ **Priority Queue System** - Uses priority queues with custom comparators for efficient order sorting  
✅ **Automatic Matching** - Matches orders based on price and timestamp priority  
✅ **Trade Execution** - Executes trades when orders can be matched  
✅ **Partial Fill Support** - Handles partial order fills when quantities don't match  
✅ **FIFO Priority** - Respects timestamp-based priority for orders at the same price  
✅ **Order Book Visualization** - Display current buy/sell orders with details  

## Architecture

### Core Components

```
┌─────────────────────────────────────────────────┐
│         MatchingEngine                          │
│  - Processes incoming orders                    │
│  - Triggers order matching logic                │
├─────────────────────────────────────────────────┤
│         OrderBook                               │
│  - Maintains buy/sell order queues              │
│  - Applies priority rules                       │
├─────────────────────────────────────────────────┤
│  Buy Orders (Priority Queue)   Sell Orders      │
│  - Highest price first         - Lowest price   │
│  - FIFO within same price      - FIFO within    │
└─────────────────────────────────────────────────┘
```

### Key Classes

| Class | Responsibility |
|-------|-----------------|
| `Order` | Represents a single trade order with metadata |
| `OrderBook` | Manages buy/sell order priority queues and matching |
| `MatchingEngine` | Orchestrates order processing and execution |

## Project Structure

```
Stock-x-change/
├── CMakeLists.txt              # Build configuration
├── Readme.md                   # This file
├── include/
│   ├── Order.h                 # Order struct definition
│   ├── OrderBook.h             # OrderBook class with comparators
│   └── MatchingEngine.h        # MatchingEngine class
├── src/
│   ├── main.cpp                # Entry point and example usage
│   ├── Order.cpp               # Order constructor
│   ├── OrderBook.cpp           # OrderBook implementation
│   └── MatchingEngine.cpp      # MatchingEngine logic
└── tests/
    └── test_cases.cpp          # Unit tests (to be implemented)
```

## Prerequisites

- **C++11** or higher
- **CMake** 3.10+
- **GCC/Clang** compiler or MSVC

### Verify Installation

```bash
cmake --version
g++ --version  # or clang++ or msvc
```

## Building

### 1. Clone and Navigate

```bash
cd Stock-x-change
```

### 2. Create Build Directory

```bash
mkdir build
cd build
```

### 3. Generate Build Files

```bash
cmake ..
```

### 4. Compile

```bash
cmake --build .
```

Or use platform-specific commands:

**Linux/Mac:**
```bash
make
```

**Windows (MSVC):**
```bash
cmake --build . --config Release
```

### 5. Run

**Linux/Mac:**
```bash
./MatchingEngine
```

**Windows:**
```bash
.\Release\MatchingEngine.exe
```

## Usage

### Basic Example

```cpp
#include "MatchingEngine.h"

int main() {
    MatchingEngine engine;
    
    // Add a buy order: 100 shares of AAPL at $150
    engine.processOrder(Order(1, "AAPL", 150.0, 100, BUY, 1));
    
    // Add a sell order: 50 shares of AAPL at $149
    // This will match with the buy order at $149 (seller's price)
    engine.processOrder(Order(2, "AAPL", 149.0, 50, SELL, 2));
    
    // Display the order book
    engine.displayOrderBook();
    
    return 0;
}
```

## How It Works

### 1. Order Submission

Orders are submitted to the matching engine with:
- Order ID (unique identifier)
- Symbol (stock ticker)
- Price (limit price)
- Quantity (number of shares)
- Type (BUY or SELL)
- Timestamp (order submission time)

### 2. Order Book Maintenance

- **Buy Orders**: Sorted by highest price first, then earliest timestamp
- **Sell Orders**: Sorted by lowest price first, then earliest timestamp

### 3. Order Matching

When a new order is added:
1. The engine checks if it can match with opposing orders
2. If buy price ≥ sell price, a trade occurs
3. Trade executes at the **sell price** (seller's limit)
4. Partial fills are handled by updating quantities
5. Process continues until no more matches possible

## Order Matching Algorithm

The matching algorithm follows these rules:

```
While (Buy Orders exist AND Sell Orders exist):
    1. Get top buy order (highest price, earliest timestamp)
    2. Get top sell order (lowest price, earliest timestamp)
    
    If (buy_price >= sell_price):
        3. Calculate trade quantity = min(buy_quantity, sell_quantity)
        4. Execute trade at sell_price
        5. Update quantities
        6. Remove fully-filled orders
        7. Re-queue partially-filled orders
    Else:
        8. Break (no more matches possible)
```

## Example

Running the default main.cpp produces:

```
Trade executed: 50 shares at $149
Buy Orders:
ID: 1, Symbol: AAPL, Price: $150, Quantity: 50, Timestamp: 1
ID: 3, Symbol: AAPL, Price: $151, Quantity: 200, Timestamp: 3

Sell Orders:
ID: 4, Symbol: AAPL, Price: $148, Quantity: 100, Timestamp: 4
```

## Testing

To run tests:

```bash
# Build tests
cmake --build . --target test

# Run with verbose output
ctest --verbose
```

**Note:** Test cases are to be implemented in `tests/test_cases.cpp`

## Contributing

Contributions are welcome! Please follow these guidelines:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Areas for Contribution

- Implement comprehensive unit tests
- Add multi-symbol support
- Implement order cancellation
- Add performance benchmarking
- Extend with advanced matching rules
- Improve documentation

## Future Enhancements

- [ ] Order cancellation functionality
- [ ] Multiple stock symbol management
- [ ] Trade history/audit log
- [ ] Order modification capabilities
- [ ] Performance metrics and analytics
- [ ] Distributed order book
- [ ] WebSocket API for real-time updates
- [ ] Comprehensive error handling

## License


---



