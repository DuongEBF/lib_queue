# Queue Implementations in C

This project provides multiple implementations of queues in C, including:
- A basic linear queue (`Queue.c`)
- A circular queue (`Queue_circular.c`)
- A structured queue for array blocks (`queue_struct.c`)
Each implementation is used in different `main` examples (`main.c`, `bt1.c`, `bt2.c`) to demonstrate real-time queue operations.

---

## 📁 Project Structure

- `Queue.h` / `Queue.c` – Basic queue (non-circular).
- `Queue_circular.c` – Circular queue variant using modulo indexing.
- `queue_struct.h` / `queue_struct.c` – Queue that supports block array buffering (e.g., to buffer multiple arrays).
- `bt1.c` – Demonstration of enqueuing/dequeuing integers using the linear queue.
- `bt2.c` – Demonstration using the structured queue with dynamic data length.
- `main.c` – Demonstrates basic queue operations with print output.

---

## 🧠 Feature Overview

### Linear Queue (`Queue.c`)
- Uses `front`, `rear`, and `used` counters to track queue state.
- Basic operations: `enqueue`, `dequeue`, `getFront`, `getRear`.

### Circular Queue (`Queue_circular.c`)
- Optimised for fixed-size memory using circular indexing with modulo `%`.
- Prevents fragmentation and continuous shifting of elements.

### Structured Queue (`queue_struct.c`)
- Each element is a block of integers (`buf[MAXSIZE]`) + a `len` field.
- Suitable for buffering groups of data (e.g., packets, sensor readings).

---

## ▶️ Compilation

### Compile with linear queue:
```bash
gcc main.c Queue.c -o run_linear
```

### Compile with circular queue:
```bash
gcc main.c Queue_circular.c -o run_circular
```

### Compile structured queue demo:
```bash
gcc bt2.c queue_struct.c -o run_struct
```

---

## ▶️ Run Example
```bash
./run_linear   # Output will show enqueue/dequeue operations
./run_struct   # Output will show variable-length data blocks from structured queue
```

---

## 📝 Notes

- All `create_queue()` functions allocate memory with `malloc`. Always call `free_queue()` after use.
- Structured queue buffers allow handling varying-sized data efficiently, e.g., simulated UART or data streams.

---

## 📤 Author

This project was written to experiment with different queue structures and their applications in embedded or systems programming.
