# DeltaDentDB Project

## Overview
The DeltaDentDB project is a web application developed by students for a work-related learning program (PCTO). It utilizes Blazor for the frontend, C# for backend logic, and MySQL as the database. This application manages dental clinic operations, including patient, doctor, and appointment management.

## Prerequisites
- .NET 8.0 or later
- MySQL Server 8.0 or later
- Visual Studio 2019 or JetBrains Rider 2024.1.4 or later for development

## Dependencies
- Entity Framework Core - for ORM
- Blazor - for the frontend
- MySQL.Data - for MySQL database connection

## Table of Contents
- [Installation Instructions for Windows](#installation-instructions-for-windows)
- [Installation Instructions for Ubuntu](#installation-instructions-for-ubuntu)
- [Installation Instructions for Fedora](#installation-instructions-for-fedora)
- [Installation Instructions for Debian](#installation-instructions-for-debian)
- [Installation Instructions for CentOS](#installation-instructions-for-centos)
- [Installation Instructions for Arch Linux](#installation-instructions-for-arch-linux)
- [Contributions](#contributions)

---

## Installation Instructions for Windows

### Steps
1. **Install .NET SDK**:
    - Download the .NET 8.0 SDK from the official [.NET website](https://dotnet.microsoft.com/download).
    - Run the installer and follow the on-screen instructions.

2. **Install MySQL Server**:
    - Download MySQL Server from the [MySQL website](https://dev.mysql.com/downloads/mysql/).
    - Run the installer and follow the on-screen instructions to set up MySQL Server.

3. **Clone the repository**:
    - Open Command Prompt or Git Bash.
    - Clone the repository using Git:
      ```bash
      git clone https://github.com/yourrepository/DeltaDentDB.git
      cd DeltaDentDB
      ```

4. **Restore NuGet packages**:
    - Open the solution in Visual Studio or JetBrains Rider.
    - Restore the NuGet packages via the Package Manager Console or through the IDE interface.

5. **Set up the database**:
    - Open MySQL Workbench or any MySQL client.
    - Execute the SQL script provided in `db.txt` to create the database and tables.

6. **Run the application**:
    - Start the application from your IDE by clicking the "Run" button or pressing `F5`.

---

## Installation Instructions for Ubuntu

### Steps
1. **Install .NET SDK**:
    - Follow the instructions on the [.NET website](https://dotnet.microsoft.com/download) for Ubuntu.
    - Example commands:
      ```bash
      wget https://packages.microsoft.com/config/ubuntu/22.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
      sudo dpkg -i packages-microsoft-prod.deb
      sudo apt-get update
      sudo apt-get install -y apt-transport-https
      sudo apt-get update
      sudo apt-get install -y dotnet-sdk-8.0
      ```

2. **Install MySQL Server**:
    - Use Ubuntu's package manager to install MySQL Server:
      ```bash
      sudo apt-get update
      sudo apt-get install -y mysql-server
      ```

3. **Clone and Setup the Project**:
    - Clone the repository:
      ```bash
      git clone https://github.com/yourrepository/DeltaDentDB.git
      cd DeltaDentDB
      ```
    - Restore NuGet packages and set up the database as described in the general installation instructions.

4. **Run the Application**:
    - Start the application from your IDE or via the terminal:
      ```bash
      dotnet run
      ```

---

## Installation Instructions for Fedora

### Steps
1. **Install .NET SDK**:
    - Follow the instructions on the [.NET website](https://dotnet.microsoft.com/download) for Fedora.

2. **Install MySQL Server**:
    - Use Fedora's package manager to install MySQL Server:
      ```bash
      sudo dnf install mysql-server
      sudo systemctl start mysqld
      sudo systemctl enable mysqld
      ```

3. **Clone and Setup the Project**:
    - Clone the repository:
      ```bash
      git clone https://github.com/yourrepository/DeltaDentDB.git
      cd DeltaDentDB
      ```
    - Restore NuGet packages and set up the database as described in the general installation instructions.

4. **Run the Application**:
    - Start the application from your IDE or via the terminal:
      ```bash
      dotnet run
      ```

---

## Installation Instructions for Debian

### Steps
1. **Install .NET SDK**:
    - Follow the instructions on the [.NET website](https://dotnet.microsoft.com/download) for Debian.

2. **Install MySQL Server**:
    - Use Debian's package manager to install MySQL Server:
      ```bash
      sudo apt-get update
      sudo apt-get install -y mysql-server
      ```

3. **Clone and Setup the Project**:
    - Clone the repository:
      ```bash
      git clone https://github.com/yourrepository/DeltaDentDB.git
      cd DeltaDentDB
      ```
    - Restore NuGet packages and set up the database as described in the general installation instructions.

4. **Run the Application**:
    - Start the application from your IDE or via the terminal:
      ```bash
      dotnet run
      ```

---

## Installation Instructions for CentOS

### Steps
1. **Install .NET SDK**:
    - Follow the instructions on the [.NET website](https://dotnet.microsoft.com/download) for CentOS.

2. **Install MySQL Server**:
    - Use CentOS's package manager to install MySQL Server:
      ```bash
      sudo yum install mysql-server
      sudo systemctl start mysqld
      sudo systemctl enable mysqld
      ```

3. **Clone and Setup the Project**:
    - Clone the repository:
      ```bash
      git clone https://github.com/yourrepository/DeltaDentDB.git
      cd DeltaDentDB
      ```
    - Restore NuGet packages and set up the database as described in the general installation instructions.

4. **Run the Application**:
    - Start the application from your IDE or via the terminal:
      ```bash
      dotnet run
      ```

---

## Installation Instructions for Arch Linux

### Steps
1. **Install .NET SDK**:
    - Follow the instructions on the [.NET website](https://dotnet.microsoft.com/download) for Arch Linux.

2. **Install MySQL Server**:
    - Install MySQL Server using the Arch Linux package manager:
      ```bash
      sudo pacman -S mysql
      sudo systemctl start mysqld
      sudo systemctl enable mysqld
      ```

3. **Clone and Setup the Project**:
    - Clone the repository:
      ```bash
      git clone https://github.com/yourrepository/DeltaDentDB.git
      cd DeltaDentDB
      ```
    - Restore NuGet packages and set up the database as described in the general installation instructions.

4. **Run the Application**:
    - Start the application from your IDE or via the terminal:
      ```bash
      dotnet run
      ```

---

## Contributions
Contributions to the project are welcome. Please fork the repository, make your changes, and submit a pull request following these steps:
1. **Fork the repository** on GitHub.
2. **Clone your fork**:
   ```bash
   git clone https://github.com/your-username/DeltaDentDB.git
   cd DeltaDentDB
   ```
3. **Create a new branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```
4. **Make your changes** and **commit** them:
   ```bash
   git commit -am 'Add some feature'
   ```
5. **Push to the branch**:
   ```bash
   git push origin feature/your-feature-name
   ```
6. **Submit a pull request** through the GitHub website.

---