## Task list:

[//]: # (1. Integration with an index component:)

[//]: # ()

[//]: # (1.1: Creating a new class to deal with the content index of the pages.)

[//]: # (1.2: Adding calls to update the index in the processPage function of the crawler.)

[//]: # ()

[//]: # ()

[//]: # (2. Creating a map of links between the pages:)

[//]: # ()

[//]: # (2.1: Creating a new data structure in the system that will store the links between the pages.)

[//]: # (2.2: Updating the data structure every time you download a page and generate new links.)

[//]: # ()

[//]: # ()

[//]: # (3. Creating a reverse index of words:)

[//]: # ()

[//]: # (3.1: Creating a data structure that will store the words and the pages where they appear.)

[//]: # (3.2: Implementation of a function to update the index every time a page is downloaded and its content extracted.)

[//]: # (4. Support for bounded crawl:)

[//]: # ()

[//]: # (4.1: Adding tests in the processPage function to make sure that the crawl remains within the defined domain.)

[//]: # (4.2: Using predefined parameters to define the domain.)

[//]: # (5. Limiting the number of pages to crawl:)

[//]: # ()

[//]: # (5.1: Added a variable to count the number of pages visited.)

[//]: # (5.2: Checking if the current number of pages has exceeded the limit before each crawl to a new page.)

[//]: # (6. Advanced search support:)

[//]: # ()

[//]: # (6.1: Added advanced search functions to handle single word, multiple word and word exclusion searches.)

## Work procedure for performing tasks

a. Detailing the required changes: analyzing the requirements of the current task and detailing the changes required to
meet these requirements.

b. Making the changes: making the required changes in the relevant files.

c. Add tests by prints: Add tests by prints to make sure the changes work as expected.

d. Update Makefile, README, class_diagram, gitignore if required: Update the required files according to the changes
made.

e. Making a commit that includes the changes made: The commit note will describe the changes made in a clear and
detailed manner.

## DOD's

    1. Implement a multi-threaded web crawler for efficient crawling of web pages 
    2. Start from a set of initial URLs and crawl pages within the specified domain(s) 
    3. Extract links from crawled pages and add them to the crawling queue 
    4. Parse HTML content and extract relevant data (e.g., text, links) 
    5. Utilize HTTP client libraries (e.g., libcurl, Boost.Beast) for making web requests 
    6. Use HTML parsing libraries (e.g., Gumbo Parser, Boost.Regex) for parsing HTML content 
    7. Implement thread-safe data structures for managing crawled data 
    8. Write unit tests for the crawler components 
    9. Optimize for performance and memory management
