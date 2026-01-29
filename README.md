# Linux Utilities Implementation

A collection of simplified UNIX utility implementations written in C, demonstrating systems programming fundamentals and command-line tool development.

## 🎯 Project Overview

This project recreates core Linux utilities from scratch, providing hands-on experience with file I/O, stream processing, data compression, and C systems programming. Each utility is implemented with robust error handling and follows UNIX conventions.

## 🛠️ Utilities Implemented

### `hfcat` - File Concatenation
A streamlined implementation of the classic `cat` utility for displaying file contents.

**Key Features:**
- Multiple file support with sequential processing
- Efficient buffered I/O using `fgets()` and `fputs()`
- Graceful error handling for inaccessible files
- Zero-allocation streaming for memory efficiency

**Usage:**
```bash
./hfcat file1.txt file2.txt
```

### `hfgrep` - Pattern Matching
A text search utility that filters lines containing a specified search term.

**Key Features:**
- Case-sensitive pattern matching using `strstr()`
- Support for arbitrarily long lines via `getline()`
- Standard input support for pipeline integration
- Dynamic memory management for variable-length input

**Usage:**
```bash
./hfgrep "search_term" file.txt
cat data.txt | ./hfgrep "pattern"
```

### `hfzip` - File Compression
A run-length encoding (RLE) compression tool that reduces file size by encoding consecutive character sequences.

**Key Features:**
- Binary output format (4-byte integer + 1-byte character)
- Multi-file compression with temporary file handling
- Shell redirection support for output management
- Efficient character-by-character streaming

**Usage:**
```bash
./hfzip input.txt > compressed.z
./hfzip file1.txt file2.txt > combined.z
```

**Compression Format:**
```
Input:  "aaaabbbb"
Output: [4-byte: 4][1-byte: 'a'][4-byte: 4][1-byte: 'b']
```

### `hfunzip` - File Decompression
Decompresses RLE-encoded files back to their original form.

**Key Features:**
- Binary file reading with `fread()`
- Validates compressed file format integrity
- Stream-based output for large file support
- Proper EOF handling for malformed inputs

**Usage:**
```bash
./hfunzip compressed.z > output.txt
```

## 🔧 Technical Implementation

### Core Technologies
- **Language:** C (C99 standard)
- **I/O Operations:** `fopen()`, `fread()`, `fwrite()`, `fgets()`, `getline()`
- **String Processing:** `strstr()`, buffer management
- **Memory Management:** Dynamic allocation with `getline()`, proper cleanup
- **Binary I/O:** Direct integer/character binary writes

### Design Decisions

**hfcat:**
- Fixed 100-byte buffer size balances memory usage and I/O efficiency
- Exits immediately on first file error (fail-fast approach)

**hfgrep:**
- Uses `getline()` instead of `fgets()` to handle arbitrarily long lines
- Implements zero-copy pattern matching with `strstr()`

**hfzip/hfunzip:**
- Temporary file approach allows multi-file compression into single stream
- 4-byte integers ensure compatibility across systems (platform-dependent, but consistent)
- Binary format optimizes for simplicity over compression ratio

## 📊 Compilation & Testing

### Build Instructions
```bash
# Compile with strict warnings enabled
gcc -o hfcat hfcat.c -Wall -Werror
gcc -o hfgrep hfgrep.c -Wall -Werror
gcc -o hfzip hfzip.c -Wall -Werror
gcc -o hfunzip hfunzip.c -Wall -Werror
```

### Example Workflows
```bash
# File viewing
./hfcat README.md

# Search operations
./hfgrep "TODO" *.c

# Compression pipeline
./hfzip largefile.txt > compressed.z
./hfunzip compressed.z > restored.txt
diff largefile.txt restored.txt  # Verify integrity
```

## 🎓 Learning Outcomes

This project demonstrates proficiency in:

- **Systems Programming:** Low-level file operations, binary I/O, stream processing
- **C Programming:** Pointer manipulation, memory management, error handling
- **UNIX Philosophy:** Small, composable tools with standard I/O integration
- **Software Engineering:** Code organization, error propagation, edge case handling

## 🔍 Error Handling

All utilities implement comprehensive error checking:
- File access validation before operations
- Null pointer checks for all system calls
- Proper exit codes (0 for success, 1 for errors)
- Descriptive error messages following UNIX conventions

## 📝 Code Quality

- **Compiler Flags:** Passes `-Wall -Werror` (all warnings treated as errors)
- **Memory Safety:** No memory leaks (verified with valgrind during development)
- **Style Consistency:** Clear variable naming, consistent formatting
- **Documentation:** Inline comments for complex logic

## 🚀 Future Enhancements

Potential improvements for expanded functionality:
- Add regex support to `hfgrep` using POSIX regex library
- Implement Huffman coding for better compression ratios in `hfzip`
- Add colorized output option for `hfgrep` matches
- Support for `-r` recursive directory traversal in `hfcat`
- Progress indicators for large file operations

## 📄 License

Academic project completed as part of systems programming coursework.

---

**Author:** Griffin Kuchar
**Course:** Operating Systems
**Date:** January 2026

*Built with attention to UNIX principles and modern C programming practices.*