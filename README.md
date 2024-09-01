# Randomized HTTP Request Sender (C)

## Overview

`randomized-http-request-sender-c` is a C program that sends HTTP GET requests to a specified URL with randomized headers. This tool allows you to test how a server responds to various user agents, referrers, accept languages, and other HTTP headers. The requests are continuously sent in an infinite loop, making it useful for stress testing or load testing.

## Features

- **Randomized Headers:** User-Agent, Referer, Accept-Language, Accept, and Connection headers.
- **Random Query Parameters:** Adds various query parameters to the URL to simulate different request scenarios.
- **Infinite Loop:** Continuously sends requests until the program is manually stopped.

## Requirements

- **libcurl:** The program uses `libcurl` for sending HTTP requests. Ensure that `libcurl` is installed on your system.
- **GCC:** To compile the program, GCC or another C compiler is required.

## Installation

1. **Install libcurl:** Follow the instructions for your operating system to install `libcurl`. For example, on Ubuntu, you can install it using:
   ```bash
   sudo apt-get install libcurl4-openssl-dev
   ```

2. **Clone the Repository:**
   ```bash
   git clone https://github.com/nomadsdev/randomized-http-request-sender-c.git
   ```

3. **Compile the Program:**
   Navigate to the project directory and compile the program using:
   ```bash
   gcc -o randomized_http randomized_http.c -lcurl
   ```

## Usage

Run the compiled program to start sending requests:
```bash
./randomized_http
```

The program will continuously send HTTP GET requests to the specified URL (`https://th.shp.ee/4lly4dh?smtt=0.0.9` in this case) with randomized headers and query parameters.

## Configuration

You can modify the following settings in `randomized_http.c`:

- **Base URL:** Change the `url` variable to the target URL.
- **User-Agent List:** Modify the list in `random_user_agent()` to include different user agents.
- **Referer List:** Modify the list in `random_referer()` to include different referers.
- **Accept-Language List:** Modify the list in `random_accept_language()` to include different accept-languages.
- **Accept List:** Modify the list in `random_accept()` to include different accept headers.
- **Connection List:** Modify the list in `random_connection()` to include different connection headers.
- **Query Parameters List:** Modify the list in `random_query_parameter()` to include different query parameters.

## License

This project is licensed under the MIT License.

## Contact

For any questions or issues, please contact:
- Email: proleak@jmmentertainment.com

## Repository

Find the project repository at: [https://github.com/nomadsdev/randomized-http-request-sender-c](https://github.com/nomadsdev/randomized-http-request-sender-c)
