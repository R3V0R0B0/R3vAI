#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

// Function to convert string to lowercase
std::string toLowerCase(const std::string& input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to generate random response from a list of options
std::string getRandomResponse(const std::vector<std::string>& responses) {
    return responses[std::rand() % responses.size()];
}

// Function to calculate Levenshtein distance
int levenshteinDistance(const std::string& a, const std::string& b) {
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1));

    for (int i = 0; i <= a.size(); ++i)
        dp[i][0] = i;
    for (int j = 0; j <= b.size(); ++j)
        dp[0][j] = j;

    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
        }
    }
    return dp[a.size()][b.size()];
}

// Function to find the closest match in the response map
std::string findClosestMatch(const std::string& input, const std::unordered_map<std::string, std::vector<std::string>>& responseMap) {
    int minDistance = std::numeric_limits<int>::max();
    std::string closestMatch;

    for (const auto& pair : responseMap) {
        int distance = levenshteinDistance(input, pair.first);
        if (distance < minDistance) {
            minDistance = distance;
            closestMatch = pair.first;
        }
    }

    return (minDistance <= 2) ? closestMatch : "";  // Threshold for considering it a close match
}

// Function to generate a response based on input
std::string generateResponse(const std::string& input, std::unordered_map<std::string, std::string>& memory) {
    std::unordered_map<std::string, std::vector<std::string>> dynamicResponseMap = {
        {"hello", {"Hello! How can I assist you?", "Hi there! What's on your mind?", "Greetings! How may I help you today!"}},
        {"hi", {"Hi! How can I help?", "Hello! What can I do for you?", "Hey! Need assistance?"}},
        {"how are you", {"I'm just a program, but I'm doing great!", "I'm here and ready to help!", "All systems are functioning well!"}},
        {"what can i say", {"You can say hello, hi, how are you, help, what is your name, exit, weather, joke, what can you do, test, make up a story, tell a poem, and more!"}},
        {"joke", {"Why don't scientists trust atoms? Because they make up everything!", "Why did the computer go to therapy? It had too many bugs!", "Why was the math book sad? It had too many problems."}},
        {"test", {"I am functional! Ready to go!", "All systems operational!", "I am running perfectly!"}},
        {"what can you do", {"I can chat with you, generate stories, poems, jokes, and much more!", "I can assist you with conversations, stories, poems, and more!", "I'm here to help, generate random stories, poems, and jokes!"}}
    };

    // Check memory first
    if (memory.find(input) != memory.end()) {
        return memory[input];
    }

    // Check for keyword in the input and return corresponding random response
    std::string matchedKey = findClosestMatch(input, dynamicResponseMap);
    if (!matchedKey.empty()) {
        std::string response = getRandomResponse(dynamicResponseMap[matchedKey]);
        memory[input] = response;  // Store response in memory
        return response;
    }

    // Random response for unknown inputs
    std::vector<std::string> unknownResponses = {
        "I'm not sure about that. Can you ask something else?",
        "That's interesting! Let's talk about something else.",
        "I don't have the answer, but I'm here to listen."
    };

    // Default response if no keyword is matched
    return getRandomResponse(unknownResponses);
}

int main() {
    std::string userInput;
    std::unordered_map<std::string, std::string> memory;
    std::cout << "R3vAI: Hello! I'm R3vAI. How can I assist you? Ask 'what can I say' to know what to ask!\n";

    // Main chat loop
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        // Convert user input to lowercase for better matching
        userInput = toLowerCase(userInput);

        // Generate and output a response
        std::string response = generateResponse(userInput, memory);
        std::cout << "R3vAI: " << response << "\n";

        // Exit condition
        if (userInput == "exit") {
            break;
        }
    }

    return 0;
}
