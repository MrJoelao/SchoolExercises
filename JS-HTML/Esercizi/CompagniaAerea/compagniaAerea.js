// Funzioni di navigazione per il login
function showLogin() {
    document.getElementById('welcomePage').style.display = 'none';
    document.getElementById('loginPage').style.display = 'block';
    document.getElementById('employeeLoginPage').style.display = 'none';
}

function showEmployeeLogin() {
    document.getElementById('welcomePage').style.display = 'none';
    document.getElementById('loginPage').style.display = 'none';
    document.getElementById('employeeLoginPage').style.display = 'block';
}

function showWelcome() {
    document.getElementById('welcomePage').style.display = 'block';
    document.getElementById('loginPage').style.display = 'none';
    document.getElementById('employeeLoginPage').style.display = 'none';
}

// Funzioni per il login
function handleCustomerLogin() {
    // Qui andrà la logica di autenticazione del cliente
    window.location.href = 'Dashboard-Customer.html';
}

function handleEmployeeLogin() {
    // Qui andrà la logica di autenticazione del dipendente
    window.location.href = 'Dashboard-Employee.html';
}

// Funzione per il logout
function logout() {
    window.location.href = 'LoginPage.html';
}

// Gestione delle sezioni della dashboard
function showDashboardSection(sectionId) {
    const sections = document.querySelectorAll('.dashboard-section');
    sections.forEach(section => {
        section.style.display = 'none';
        if (section.id === sectionId) {
            section.style.display = 'block';
        }
    });

    // Aggiorna la navigazione attiva
    const navLinks = document.querySelectorAll('.nav-link');
    navLinks.forEach(link => {
        link.classList.remove('active');
        if (link.getAttribute('onclick').includes(sectionId)) {
            link.classList.add('active');
        }
    });
}

// Funzione per aggiornare data e ora
function updateDateTime() {
    const now = new Date();
    const options = { 
        weekday: 'long', 
        year: 'numeric', 
        month: 'long', 
        day: 'numeric',
        hour: '2-digit',
        minute: '2-digit'
    };
    const dateTimeString = now.toLocaleDateString('it-IT', options);
    document.getElementById('currentDateTime').textContent = dateTimeString;
}

// Inizializzazione quando il documento è caricato
document.addEventListener('DOMContentLoaded', function() {
    // Aggiorna data e ora immediatamente e ogni minuto
    updateDateTime();
    setInterval(updateDateTime, 60000);

    // Controlla in quale pagina siamo
    const isLoginPage = document.querySelector('.login-container');
    const isDashboard = document.querySelector('.dashboard-container');

    if (isLoginPage) {
        // Gestione del login cliente
        const customerLoginBtn = document.querySelector('.login-btn:not(.employee-btn)');
        if (customerLoginBtn) {
            customerLoginBtn.addEventListener('click', function(e) {
                e.preventDefault();
                handleCustomerLogin();
            });
        }

        // Gestione del login dipendenti
        const employeeLoginBtn = document.querySelector('.employee-btn');
        if (employeeLoginBtn) {
            employeeLoginBtn.addEventListener('click', function(e) {
                e.preventDefault();
                handleEmployeeLogin();
            });
        }

        // Gestione della visibilità della password
        const togglePasswords = document.querySelectorAll('.toggle-password');
        togglePasswords.forEach(toggle => {
            toggle.addEventListener('click', function() {
                const passwordInput = this.previousElementSibling;
                const type = passwordInput.getAttribute('type') === 'password' ? 'text' : 'password';
                passwordInput.setAttribute('type', type);
                this.classList.toggle('fa-eye');
                this.classList.toggle('fa-eye-slash');
            });
        });
    }

    if (isDashboard) {
        // Mostra la sezione overview all'avvio
        showDashboardSection('overview');

        // Gestione della ricerca
        const searchInputs = document.querySelectorAll('.search-bar input');
        searchInputs.forEach(input => {
            input.addEventListener('input', function() {
                // Implementare la logica di ricerca
                console.log('Searching:', this.value);
            });
        });

        // Gestione dei filtri
        const filterSelects = document.querySelectorAll('.filter-group select');
        filterSelects.forEach(select => {
            select.addEventListener('change', function() {
                // Implementare la logica di filtro
                console.log('Filter changed:', this.value);
            });
        });
    }
});
