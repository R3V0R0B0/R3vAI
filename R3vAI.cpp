#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

// Function to convert a string to lowercase
std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to fetch a random response from a list of possible responses
std::string getRandomResponse(const std::vector<std::string>& responses) {
    if (responses.empty()) return "Sorry, I don't know how to respond to that.";
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % responses.size();
    return responses[index];
}

// Function to generate a response based on the input and memory
std::string generateResponse(const std::string& input, std::unordered_map<std::string, std::vector<std::string>>& memory) {
    std::unordered_map<std::string, std::vector<std::string>> dynamicResponseMap = {
        {"hello", {"Hello! How can I assist you today?", "Hi there! What brings you here?", "Greetings! Ready to chat?"}},
        {"hi", {"Hey there! What can I do for you?", "Hello! How's it going?", "Hi! Need any help?"}},
        {"how are you", {"I'm just code, but I'd say I'm feeling 'optimal'!", "I'm great! Ready to help.", "All systems running smoothly. How about you?"}},
        {"what is your name", {"I'm R3vAI, your virtual assistant with a personality!", "You can call me R3vAI, at your service.", "R3vAI is the name, helping is the game!"}},
        {"weather", {"I can't check the real weather, but I bet it's a good day to chat!", "I'm not connected to weather services, but let's focus on our conversation!"}},
        {"joke", {"Why don't robots ever get tired? Because they recharge!", "I told a joke once… but it ran out of memory.", "What do you call a computer that sings? A Dell!"}},
        {"what can you do", {"I can chat, generate stories, tell jokes, and more! Give it a try.", "I'm here to help with conversations, questions, or random fun.", "Need advice? A joke? Or just want to chat? I'm your AI."}},
        {"test", {"All systems are a-go!", "Testing complete. Everything's functional!", "I'm working perfectly, ready when you are!"}},
        {"what can i say", {"Ask me about the weather, tell a joke, or chat! You can say things like: 'hi', 'how are you', 'weather', 'what can you do', and more."}},
        {"why so specific", {"Details make a difference! That's why I'm precise.", "Being specific helps me give better responses!", "Precision is key to great conversation!"}},
        {"r3vai reset", {"I'm here to chat, but resetting isn't something I can do. Maybe we can restart our conversation instead?"}},
        {"good", {"nice!", "ok, well, being good isn't amazing", "I'm good as well!, well, as good as AI can be!"}},
        {"amazing", {"Perfect, ya me 2"}},
        {"bad", {"oh sorry to hear that"}},
        {"ok", {"OK? just OK?"}},
        {"how do you work", {"u wanna know? I'll run it down fo ya, if I don't have a response I'll tell ya, I have a lot of pre-generated messages, and I randomly choose them, then send them, that's a simple rundown!"}},
    };

    // Check if the input matches any known phrases
    std::string lowerInput = toLowerCase(input);
    if (dynamicResponseMap.find(lowerInput) != dynamicResponseMap.end()) {
        return getRandomResponse(dynamicResponseMap[lowerInput]);
    }

    // Memory response for unknown inputs
    if (memory.find(lowerInput) != memory.end()) {
        return getRandomResponse(memory[lowerInput]);
    }

    // If input isn't recognized
    std::vector<std::string> unknownResponses = {
        "I'm not sure about that. Can you ask something else?",
        "That's interesting! Let's talk about something else.",
        "I don't have the answer, but I'm here to listen."
    };
    return getRandomResponse(unknownResponses);
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> memory;
    std::string userInput;

    std::cout << "R3vAI: Hello! I'm R3vAI. How can I assist you? Ask 'what can I say' to know what to ask!" << std::endl;

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        // Handle exit
        if (toLowerCase(userInput) == "exit") {
            std::cout << "R3vAI: Goodbye! Come back if you need more help!" << std::endl;
            break;
        }

        // Generate a response
        std::string response = generateResponse(userInput, memory);
        std::cout << "R3vAI: " << response << std::endl;
    }

    return 0;
}
