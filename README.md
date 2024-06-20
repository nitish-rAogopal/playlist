# Playlist Manager

This project is a simple playlist manager implemented in C. It allows you to create, manage, and play songs in a playlist using a doubly circular linked list. The program provides functionality to add, delete, shuffle, and navigate through songs.

## Features

- Add new songs to the playlist
- Delete existing songs from the playlist
- Display all songs in the playlist
- Play the next song in the playlist
- Play the previous song in the playlist
- Play a specific song from the playlist
- Shuffle two songs in the playlist
- Play the first song in the playlist
- Supports looped and non-looped playlist modes

## Structs

### SONG

```c
struct s {
    char song_name[100];
    char singer_name[100];
    char genre[100];
};
typedef struct s SONG;
```

### playLL

```c
struct node {
    SONG song;
    struct node *next;
    struct node *prev;
};
typedef struct node playLL;
```

## Functions

### readSong

    ```sh
    void readSong(SONG s)
    ```
Prints the details of a song.

### inserAtLast

    ```sh
    playLL *inserAtLast(SONG sng)
    ```
Inserts a new song at the end of the playlist.

### readPlayLL

    ```sh
    void readPlayLL()
    ```
Displays all songs in the playlist.

### matching

    ```sh
    int matching(SONG sf, SONG st)
    ```
Checks if two songs are the same based on their names.

### deleteSong

    ```sh
    playLL *deleteSong(SONG s, int isLoop)
    ```
Deletes a specific song from the playlist.

### playParticular

    ```sh
    void playParticular(SONG s)
    ```
Plays a specific song from the playlist.

### playFirst

    ```sh
    void playFirst()
    ```
Plays the first song in the playlist.

### shuffleSong

    ```sh
    playLL *shuffleSong(SONG s1, SONG s2)
    ```
Shuffles two songs in the playlist.

### playNext

    ```sh
    void playNext(int isLoop)
    ```
Plays the next song in the playlist.

### playPrevious

    ```sh
    void playPrevious(int isLoop)
    ```
Plays the previous song in the playlist.

### playListPrompt

    ```sh
    int playListPrompt(int isloop)
    ```
Prompts the user to interact with the playlist.

### main

    ```sh
    int main()
    ```
Main function that runs the program and handles the user's choices.

## How to Compile and Run

1. Clone the repository.
2. Navigate to the directory containing the source code.
3. Compile the program using a C compiler (e.g., `gcc`).
```sh
gcc playlist.c -o playlist.exe
```

4. Run the compiled program.
```sh
./playlist.exe
```
## Usage

1. Choose between looped or non-looped playlist mode.
2. Use the menu to interact with the playlist:
      - Insert a new song
      - Delete a song
      - Display all songs
      - Play the next song
      - Play the previous song
      - Play a specific song
      - Shuffle two songs
      - Play the first song
      - Exit the program

## Future Improvements

While the current implementation of the Playlist Manager is functional, there are several areas where enhancements can be made. Here are some potential future improvements:

### User Interface

- **Graphical User Interface (GUI):** Develop a GUI to make the playlist manager more user-friendly and visually appealing.
- **Command-Line Improvements:** Enhance the command-line interface to support more intuitive commands and better error handling.

### Features

- **Search Functionality:** Add the ability to search for songs by name, singer, or genre.
- **Sorting:** Implement sorting options to sort songs by name, singer, or genre.
- **Playlists:** Support multiple playlists, allowing users to create, manage, and switch between different playlists.
- **Repeat and Shuffle Modes:** Enhance the play functionality to support repeat and shuffle modes.
- **Play Queue:** Implement a play queue that users can add songs to and manage.

### Data Persistence

- **Save and Load Playlists:** Implement functionality to save playlists to a file and load them from a file, allowing users to persist their playlists across sessions.
- **Database Integration:** Integrate with a database to manage songs and playlists, enabling more scalable and robust data handling.

### Performance

- **Optimization:** Optimize the current code to improve performance, especially for large playlists.
- **Memory Management:** Improve memory management to handle dynamic memory allocation more efficiently and prevent memory leaks.

### Code Quality

- **Refactoring:** Refactor the code to improve readability, maintainability, and modularity. Break down large functions into smaller, more manageable ones.
- **Testing:** Implement unit tests to ensure the correctness of the code and facilitate future changes and improvements.

### Documentation

- **Detailed Documentation:** Expand the documentation to include detailed descriptions of each function, their parameters, and return values.
- **User Guide:** Create a comprehensive user guide that provides detailed instructions on how to use the playlist manager and its features.

### Compatibility

- **Cross-Platform Support:** Ensure the playlist manager is compatible with multiple operating systems (Windows, macOS, Linux).
- **Standard Libraries:** Replace platform-specific libraries (e.g., `conio.h`) with standard C libraries to improve portability.

### Community Contributions

- **Contribution Guidelines:** Develop clear contribution guidelines to encourage community involvement and contributions to the project.
- **Issue Tracker:** Implement an issue tracker to manage bugs, feature requests, and other contributions from the community.

By implementing these improvements, the Playlist Manager can become a more robust, user-friendly, and feature-rich application.

## LICENSE

This project is licensed under the MIT License. See the LICENSE file for details.
```
This `README.md` provides an overview of the project, its features, and instructions on how to compile and run the program. Adjust the content as needed to better suit your project's specifics.
