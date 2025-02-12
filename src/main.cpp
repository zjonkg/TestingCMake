#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

void logMessage(const std::string &message) {
    // Obtener el tiempo actual
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    char timeStr[26];

    #ifdef _WIN32
        ctime_s(timeStr, sizeof(timeStr), &now_time);  // Windows
    #else
        ctime_r(&now_time, timeStr);  // Linux / macOS
    #endif

    // Abrir el archivo de log en modo append
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << timeStr << " - " << message << std::endl;
        logFile.close();
    } else {
        std::cerr << "Error al abrir el archivo de log." << std::endl;
    }
}

int main() {
    std::cout << "Hola mundijirillo!" << std::endl;
    logMessage("Se mostró 'Hola, mundo!' en la consola.");
    return 0;
}
