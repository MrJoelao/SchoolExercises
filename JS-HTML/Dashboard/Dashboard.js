// Dati degli esercizi
const exercises = [
    {
        id: 1,
        title: "HTML Basics",
        description: "Introduzione ai tag HTML fondamentali",
        difficulty: "Principiante",
        tags: ["HTML", "Base"],
        status: "completed"
    },
    {
        id: 2,
        title: "CSS Flexbox",
        description: "Layout responsive con Flexbox",
        difficulty: "Intermedio",
        tags: ["CSS", "Flexbox", "Layout"],
        status: "in-progress"
    },
    // Aggiungi altri esercizi qui...
];

// Gestione del tema
class ThemeManager {
    constructor() {
        this.themes = {
            'dark': {
                name: 'Dark',
                icon: 'dark_mode',
                colors: {
                    '--background': '#282828',
                    '--background-alt': '#3c3836',
                    '--background-hover': '#504945',
                    '--foreground': '#ebdbb2',
                    '--primary': '#fe8019',
                    '--primary-rgb': '254, 128, 25'
                }
            },
            'light': {
                name: 'Light',
                icon: 'light_mode',
                colors: {
                    '--background': '#fbf1c7',
                    '--background-alt': '#ebdbb2',
                    '--background-hover': '#d5c4a1',
                    '--foreground': '#3c3836',
                    '--primary': '#d65d0e',
                    '--primary-rgb': '214, 93, 14'
                }
            },
            'nord': {
                name: 'Nord',
                icon: 'ac_unit',
                colors: {
                    '--background': '#2e3440',
                    '--background-alt': '#3b4252',
                    '--background-hover': '#434c5e',
                    '--foreground': '#eceff4',
                    '--primary': '#88c0d0',
                    '--primary-rgb': '136, 192, 208'
                }
            },
            'dracula': {
                name: 'Dracula',
                icon: 'nights_stay',
                colors: {
                    '--background': '#282a36',
                    '--background-alt': '#44475a',
                    '--background-hover': '#6272a4',
                    '--foreground': '#f8f8f2',
                    '--primary': '#bd93f9',
                    '--primary-rgb': '189, 147, 249'
                }
            }
        };

        this.themeToggle = document.getElementById('themeToggle');
        this.currentTheme = localStorage.getItem('theme') || 'dark';
        this.initTheme();
        this.setupEventListeners();
    }

    initTheme() {
        this.applyTheme(this.currentTheme);
        this.updateThemeIcon();
    }

    applyTheme(themeName) {
        const theme = this.themes[themeName];
        if (!theme) return;

        // Trova la preview attualmente attiva e rimuovi la classe
        const currentPreview = document.querySelector('.theme-preview.active');
        if (currentPreview) {
            currentPreview.classList.remove('active');
        }

        // Trova la nuova preview e aggiungi le classi per l'animazione
        const newPreview = document.querySelector(`.theme-preview[data-theme="${themeName}"]`);
        if (newPreview) {
            newPreview.classList.add('active', 'applying');
            
            // Rimuovi la classe 'applying' dopo l'animazione
            setTimeout(() => {
                newPreview.classList.remove('applying');
            }, 500);
        }

        // Applica il tema con una leggera latenza per permettere all'animazione di iniziare
        setTimeout(() => {
            Object.entries(theme.colors).forEach(([property, value]) => {
                document.documentElement.style.setProperty(property, value);
            });
            
            this.currentTheme = themeName;
            localStorage.setItem('theme', themeName);
        }, 150);
    }

    setupEventListeners() {
        this.themeToggle.addEventListener('click', () => {
            this.showThemeSelector();
        });
    }

    showThemeSelector() {
        const modal = document.createElement('div');
        modal.className = 'modal active';
        modal.innerHTML = `
            <div class="modal-content theme-selector-modal">
                <div class="modal-header">
                    <h2>
                        <span class="material-icons">palette</span>
                        Seleziona Tema
                    </h2>
                    <button class="close-modal">
                        <span class="material-icons">close</span>
                    </button>
                </div>
                <div class="themes-grid">
                    ${Object.entries(this.themes).map(([id, theme]) => `
                        <div class="theme-preview ${this.currentTheme === id ? 'active' : ''}" 
                             data-theme="${id}"
                             style="--preview-bg: ${theme.colors['--background']};
                                    --preview-bg-alt: ${theme.colors['--background-alt']};
                                    --preview-primary: ${theme.colors['--primary']};
                                    --preview-text: ${theme.colors['--foreground']};">
                            <div class="preview-header">
                                <span class="material-icons" style="color: ${theme.colors['--primary']}">${theme.icon}</span>
                            </div>
                            <div class="preview-content">
                                <div class="preview-title" style="color: ${theme.colors['--foreground']}">${theme.name}</div>
                                <div class="preview-bar" style="background: ${theme.colors['--background-alt']}"></div>
                                <div class="preview-bar" style="background: ${theme.colors['--background-alt']}"></div>
                            </div>
                            ${this.currentTheme === id ? `
                                <div class="theme-active">
                                    <span class="material-icons">check_circle</span>
                                </div>
                            ` : ''}
                        </div>
                    `).join('')}
                </div>
            </div>
        `;

        document.body.appendChild(modal);

        // Event Listeners
        modal.querySelector('.close-modal').addEventListener('click', () => {
            this.closeThemeModal(modal);
        });

        modal.addEventListener('click', (e) => {
            if (e.target === modal) {
                this.closeThemeModal(modal);
            }
        });

        modal.querySelectorAll('.theme-preview').forEach(preview => {
            preview.addEventListener('click', () => {
                const themeId = preview.dataset.theme;
                
                modal.querySelectorAll('.theme-preview').forEach(p => {
                    p.classList.remove('active', 'applying');
                });
                
                preview.classList.add('active');
                
                this.applyTheme(themeId);
                this.updateThemeIcon();
                
                this.closeThemeModal(modal);
            });
        });
    }

    closeThemeModal(modal) {
        modal.classList.add('closing');
        modal.querySelector('.modal-content').style.animation = 'modalExit 0.3s cubic-bezier(0.4, 0, 0.2, 1) forwards';
        
        setTimeout(() => {
            modal.remove();
        }, 300);
    }

    updateThemeIcon() {
        const theme = this.themes[this.currentTheme];
        if (theme) {
            this.themeToggle.querySelector('.material-icons').textContent = theme.icon;
        }
    }
}

// Gestione degli esercizi
class ExerciseManager {
    constructor() {
        this.exercises = JSON.parse(localStorage.getItem('exercises')) || [];
        this.exerciseGrid = document.querySelector('.exercise-grid');
        this.searchInput = document.getElementById('searchExercises');
        this.addExerciseBtn = document.getElementById('addExerciseBtn');
        this.modal = document.getElementById('addExerciseModal');
        this.form = document.getElementById('exerciseForm');
        this.currentEditId = null;
        
        this.setupEventListeners();
        this.renderExercises();
    }

    setupEventListeners() {
        // Ricerca
        this.searchInput.addEventListener('input', () => this.handleSearch());
        
        // Modal
        this.addExerciseBtn.addEventListener('click', () => this.openModal());
        document.querySelectorAll('.close-modal').forEach(btn => {
            btn.addEventListener('click', () => this.closeModal());
        });
        
        // Form
        this.form.addEventListener('submit', (e) => {
            e.preventDefault();
            this.handleSubmit(e);
            // Forza la chiusura del modal dopo il submit
            setTimeout(() => {
                this.modal.classList.remove('active');
                document.body.style.overflow = '';
                this.form.reset();
                this.currentEditId = null;
            }, 0);
        });
        
        // Chiudi modal se si clicca fuori
        this.modal.addEventListener('click', (e) => {
            if (e.target === this.modal) this.closeModal();
        });

        // Tab navigation con animazione
        const formTabs = document.querySelector('.form-tabs');
        document.querySelectorAll('.tab-btn').forEach(btn => {
            btn.addEventListener('click', (event) => {
                event.preventDefault();
                
                document.querySelectorAll('.tab-btn').forEach(b => b.classList.remove('active'));
                btn.classList.add('active');
                
                // Aggiunge l'attributo per l'animazione
                formTabs.dataset.active = btn.dataset.tab;
                
                document.querySelectorAll('.tab-content').forEach(content => {
                    content.classList.remove('active');
                    content.style.display = 'none';
                });
                const targetContent = document.querySelector(`.tab-content[data-tab="${btn.dataset.tab}"]`);
                targetContent.classList.add('active');
                targetContent.style.display = 'block';
            });
        });

        // Status filters con animazione
        const statusFilters = document.querySelector('.status-filters');
        document.querySelectorAll('.filter-btn').forEach(btn => {
            btn.addEventListener('click', () => {
                document.querySelectorAll('.filter-btn').forEach(b => b.classList.remove('active'));
                btn.classList.add('active');
                statusFilters.dataset.active = btn.dataset.status; // Aggiunge l'attributo per l'animazione
                const status = btn.dataset.status;
                const filtered = status === 'all' 
                    ? this.exercises 
                    : this.exercises.filter(ex => ex.status === status);
                this.renderExercises(filtered);
            });
        });
    }

    handleSearch() {
        const searchTerm = this.searchInput.value.toLowerCase();
        const filteredExercises = this.exercises.filter(exercise => 
            exercise.title.toLowerCase().includes(searchTerm) ||
            exercise.description.toLowerCase().includes(searchTerm) ||
            exercise.tags.some(tag => tag.toLowerCase().includes(searchTerm))
        );
        this.renderExercises(filteredExercises);
    }

    openModal() {
        this.form.reset();
        this.currentEditId = null;
        
        // Imposta il tab iniziale anche per l'animazione
        const formTabs = document.querySelector('.form-tabs');
        formTabs.dataset.active = 'basic';
        
        // Reset dei tab e mostra il primo contenuto
        document.querySelectorAll('.tab-btn').forEach(btn => btn.classList.remove('active'));
        document.querySelector('.tab-btn[data-tab="basic"]').classList.add('active');
        
        document.querySelectorAll('.tab-content').forEach(content => {
            content.classList.remove('active');
            content.style.display = 'none';
        });
        document.querySelector('.tab-content[data-tab="basic"]').classList.add('active');
        document.querySelector('.tab-content[data-tab="basic"]').style.display = 'block';

        document.querySelector('.modal-header h2').innerHTML = `
            <span class="material-icons">add_task</span>
            Nuovo Esercizio
        `;
        document.querySelector('.form-actions .button-primary').innerHTML = `
            <span class="material-icons">save</span>
            Salva
        `;
        this.modal.classList.add('active');
        document.body.style.overflow = 'hidden';
    }

    closeModal() {
        this.modal.classList.add('closing');
        setTimeout(() => {
            this.modal.classList.remove('active', 'closing');
            document.body.style.overflow = '';
            this.form.reset();
            this.currentEditId = null;
        }, 300);
    }

    handleSubmit(e) {
        const exerciseData = {
            title: document.getElementById('exerciseTitle').value,
            path: document.getElementById('exercisePath').value.replace(/^\//, ''),
            description: document.getElementById('exerciseDescription').value,
            tags: document.getElementById('exerciseTags').value.split(',').map(tag => tag.trim()),
            difficulty: document.getElementById('exerciseDifficulty').value,
            status: document.getElementById('exerciseStatus').value,
            deadline: document.getElementById('exerciseDeadline').value || null
        };

        if (this.currentEditId) {
            const index = this.exercises.findIndex(ex => ex.id === this.currentEditId);
            if (index !== -1) {
                this.exercises[index] = {
                    ...this.exercises[index],
                    ...exerciseData,
                    dateModified: new Date().toISOString()
                };
                this.showNotification('Esercizio aggiornato con successo!');
            }
        } else {
            const newExercise = {
                id: Date.now(),
                ...exerciseData,
                dateAdded: new Date().toISOString(),
                dateCompleted: null
            };
            this.exercises.push(newExercise);
            this.showNotification('Esercizio aggiunto con successo!');
        }

        this.closeModal();
        this.saveExercises();
        this.renderExercises();
        this.updateProgress();
    }

    showNotification(message, type = 'success') {
        const notification = document.createElement('div');
        notification.className = `notification ${type}`;
        notification.textContent = message;
        document.body.appendChild(notification);
        
        setTimeout(() => {
            notification.remove();
        }, 3000);
    }

    renderExercises(exercisesToShow = this.exercises) {
        const currentCards = document.querySelectorAll('.exercise-card');
        currentCards.forEach(card => {
            card.style.animation = 'cardRemove 0.3s ease-out forwards';
        });

        setTimeout(() => {
            this.exerciseGrid.innerHTML = exercisesToShow.map(exercise => `
                <div class="exercise-card" data-id="${exercise.id}">
                    <div class="card-header">
                        <h3 class="card-title">
                            <span class="material-icons status-icon ${exercise.status}" title="${this.getStatusText(exercise.status)}">
                                ${this.getStatusIcon(exercise.status)}
                            </span>
                            ${exercise.title}
                        </h3>
                    </div>
                    
                    <div class="card-content" onclick="exerciseManager.showExerciseDetails(${exercise.id})">
                        <p class="card-description">${exercise.description}</p>
                        
                        <div class="tags-container">
                            ${exercise.tags.map(tag => `
                                <span class="tag">${tag}</span>
                            `).join('')}
                        </div>
                    </div>

                    <div class="card-actions">
                        <div class="action-buttons">
                            <button class="action-btn" 
                                    onclick="event.stopPropagation(); exerciseManager.toggleStatus(${exercise.id})"
                                    title="Cambia stato">
                                <span class="material-icons">update</span>
                            </button>
                            <button class="action-btn" 
                                    onclick="event.stopPropagation(); exerciseManager.openEditModal(${exercise.id})"
                                    title="Modifica">
                                <span class="material-icons">edit</span>
                            </button>
                            <button class="action-btn" 
                                    onclick="event.stopPropagation(); exerciseManager.deleteExercise(${exercise.id})"
                                    title="Elimina">
                                <span class="material-icons">delete</span>
                            </button>
                        </div>
                        
                        <a href="/${exercise.path}" class="action-btn primary" title="Apri esercizio">
                            <span class="material-icons">launch</span>
                        </a>
                    </div>
                </div>
            `).join('');
        }, currentCards.length ? 300 : 0);
    }

    getStatusIcon(status) {
        const icons = {
            'todo': 'assignment',
            'in-progress': 'trending_up',
            'completed': 'task_alt'
        };
        return icons[status] || 'help_outline';
    }

    getStatusText(status) {
        const texts = {
            'todo': 'Da Fare',
            'in-progress': 'In Corso',
            'completed': 'Completato'
        };
        return texts[status] || 'Sconosciuto';
    }

    showExerciseDetails(id) {
        const exercise = this.exercises.find(ex => ex.id === id);
        if (!exercise) return;

        const detailsModal = document.createElement('div');
        detailsModal.className = 'modal active';
        detailsModal.innerHTML = `
            <div class="modal-content details-modal">
                <div class="modal-header">
                    <h2>
                        <span class="material-icons status-icon ${exercise.status}">
                            ${this.getStatusIcon(exercise.status)}
                        </span>
                        ${exercise.title}
                    </h2>
                    <button class="close-modal">
                        <span class="material-icons">close</span>
                    </button>
                </div>
                <div class="exercise-details">
                    <div class="details-section">
                        <h3>Descrizione</h3>
                        <p>${exercise.description}</p>
                    </div>

                    <div class="details-section">
                        <h3>Informazioni</h3>
                        <div class="info-grid">
                            <div class="info-item">
                                <span class="info-label">Stato</span>
                                <span class="status-badge ${exercise.status}">
                                    <span class="material-icons">${this.getStatusIcon(exercise.status)}</span>
                                    ${this.getStatusText(exercise.status)}
                                </span>
                            </div>
                            <div class="info-item">
                                <span class="info-label">Difficoltà</span>
                                <span class="difficulty-badge ${exercise.difficulty.toLowerCase()}">
                                    ${exercise.difficulty}
                                </span>
                            </div>
                            <div class="info-item">
                                <span class="info-label">Percorso</span>
                                <span class="path-value">${exercise.path}</span>
                            </div>
                            ${exercise.deadline ? `
                                <div class="info-item">
                                    <span class="info-label">Scadenza</span>
                                    <span class="deadline-value">
                                        <span class="material-icons">event</span>
                                        ${new Date(exercise.deadline).toLocaleDateString()}
                                    </span>
                                </div>
                            ` : ''}
                        </div>
                    </div>

                    <div class="details-section">
                        <h3>Tags</h3>
                        <div class="tags-container">
                            ${exercise.tags.map(tag => `<span class="tag">${tag}</span>`).join('')}
                        </div>
                    </div>

                    <div class="details-section">
                        <h3>Timeline</h3>
                        <div class="timeline">
                            <div class="timeline-item">
                                <span class="material-icons">add_circle_outline</span>
                                <div>
                                    <span class="timeline-label">Aggiunto il</span>
                                    <span class="timeline-date">${new Date(exercise.dateAdded).toLocaleDateString()}</span>
                                </div>
                            </div>
                            ${exercise.dateModified ? `
                                <div class="timeline-item">
                                    <span class="material-icons">edit</span>
                                    <div>
                                        <span class="timeline-label">Ultima modifica</span>
                                        <span class="timeline-date">${new Date(exercise.dateModified).toLocaleDateString()}</span>
                                    </div>
                                </div>
                            ` : ''}
                        </div>
                    </div>
                </div>
                <div class="details-actions">
                    <a href="/${exercise.path}" class="button-primary">
                        <span class="material-icons">launch</span>
                        Apri Esercizio
                    </a>
                </div>
            </div>
        `;

        document.body.appendChild(detailsModal);

        // Event Listeners
        const closeBtn = detailsModal.querySelector('.close-modal');
        closeBtn.addEventListener('click', () => {
            detailsModal.classList.add('closing');
            setTimeout(() => detailsModal.remove(), 300);
        });

        detailsModal.addEventListener('click', (e) => {
            if (e.target === detailsModal) {
                detailsModal.classList.add('closing');
                setTimeout(() => detailsModal.remove(), 300);
            }
        });
    }

    updateProgress() {
        const total = this.exercises.length;
        const completed = this.exercises.filter(ex => ex.status === 'completed').length;
        const percentage = (completed / total) * 100 || 0;
        
        document.querySelector('.progress-fill').style.width = `${percentage}%`;
    }

    toggleStatus(id) {
        const exercise = this.exercises.find(ex => ex.id === parseInt(id));
        if (exercise) {
            const statusIcon = document.querySelector(`[data-id="${id}"] .status-icon`);
            statusIcon.classList.add('changing');
            
            setTimeout(() => {
                exercise.status = exercise.status === 'completed' ? 'todo' : 'completed';
                exercise.dateCompleted = exercise.status === 'completed' ? new Date().toISOString() : null;
                this.saveExercises();
                this.renderExercises();
                this.updateProgress();
            }, 250);
        }
    }

    saveExercises() {
        localStorage.setItem('exercises', JSON.stringify(this.exercises));
    }

    renderQuickStatusButton(exercise) {
        const statusConfig = {
            'todo': {
                nextStatus: 'in-progress',
                icon: 'play_arrow',
                title: 'Inizia'
            },
            'in-progress': {
                nextStatus: 'completed',
                icon: 'done',
                title: 'Completa'
            },
            'completed': {
                nextStatus: 'todo',
                icon: 'replay',
                title: 'Riparti'
            }
        };

        const config = statusConfig[exercise.status];
        if (!config) return '';

        return `
            <button 
                class="status-button ${exercise.status}"
                onclick="event.stopPropagation(); exerciseManager.quickUpdateStatus('${exercise.id}', '${config.nextStatus}')"
                title="${config.title}"
            >
                <span class="material-icons">${config.icon}</span>
            </button>
        `;
    }

    quickUpdateStatus(id, newStatus) {
        const exercise = this.exercises.find(ex => ex.id === parseInt(id));
        if (exercise) {
            exercise.status = newStatus;
            exercise.dateCompleted = newStatus === 'completed' ? new Date().toISOString() : null;
            this.saveExercises();
            this.renderExercises();
            this.updateProgress();
            
            this.showNotification(`Stato aggiornato: ${this.getStatusText(newStatus)}`);
        }
    }

    openEditModal(id) {
        const exercise = this.exercises.find(ex => ex.id === parseInt(id));
        if (!exercise) return;

        this.currentEditId = exercise.id;
        
        // Popola i campi del form
        document.getElementById('exerciseTitle').value = exercise.title;
        document.getElementById('exerciseDescription').value = exercise.description;
        document.getElementById('exercisePath').value = exercise.path;
        document.getElementById('exerciseTags').value = exercise.tags.join(', ');
        document.getElementById('exerciseDifficulty').value = exercise.difficulty;
        document.getElementById('exerciseStatus').value = exercise.status;
        document.getElementById('exerciseDeadline').value = exercise.deadline || '';

        // Cambia il titolo del modal
        document.querySelector('.modal-header h2').innerHTML = `
            <span class="material-icons">edit</span>
            Modifica Esercizio
        `;
        
        // Cambia il testo del pulsante submit
        document.querySelector('.form-actions .button-primary').innerHTML = `
            <span class="material-icons">save</span>
            Aggiorna
        `;
        
        // Reset e attiva il primo tab
        document.querySelectorAll('.tab-btn').forEach(btn => btn.classList.remove('active'));
        document.querySelector('.tab-btn[data-tab="basic"]').classList.add('active');
        
        document.querySelectorAll('.tab-content').forEach(content => {
            content.classList.remove('active');
            content.style.display = 'none';
        });
        document.querySelector('.tab-content[data-tab="basic"]').classList.add('active');
        document.querySelector('.tab-content[data-tab="basic"]').style.display = 'block';
        
        this.modal.classList.add('active');
        document.body.style.overflow = 'hidden';
    }

    toggleCardMenu(id) {
        const allMenus = document.querySelectorAll('.menu-dropdown');
        allMenus.forEach(menu => {
            if (menu.id !== `menu-${id}`) {
                menu.classList.remove('active');
            }
        });
        
        const menu = document.getElementById(`menu-${id}`);
        menu.classList.toggle('active');
    }

    deleteExercise(id) {
        const card = document.querySelector(`[data-id="${id}"]`);
        card.classList.add('removing');
        
        setTimeout(() => {
            this.exercises = this.exercises.filter(ex => ex.id !== id);
            this.saveExercises();
            this.renderExercises();
            this.updateProgress();
            this.showNotification('Esercizio eliminato con successo');
        }, 300);
    }

    confirmDelete(id, buttonElement) {
        // Prima rimuovi il modal di conferma
        const confirmModal = buttonElement.closest('.modal');
        if (confirmModal) {
            confirmModal.remove();
        }

        // Poi procedi con l'eliminazione
        this.exercises = this.exercises.filter(ex => ex.id !== id);
        this.saveExercises();
        this.renderExercises();
        this.updateProgress();
        
        // Chiudi anche il menu dropdown se è ancora aperto
        const menu = document.getElementById(`menu-${id}`);
        if (menu) {
            menu.classList.remove('active');
        }

        this.showNotification('Esercizio eliminato con successo');
    }
}

// Aggiungi questa classe dopo ExerciseManager
class BookManager {
    constructor() {
        this.books = JSON.parse(localStorage.getItem('books')) || [];
        this.booksGrid = document.querySelector('.books-grid');
        this.searchInput = document.getElementById('searchBooks');
        this.addBookBtn = document.getElementById('addBookBtn');
        this.modal = document.getElementById('addBookModal');
        this.form = document.getElementById('bookForm');
        this.currentEditId = null;
        
        this.setupEventListeners();
        this.renderBooks();
        this.setupFileSelection();
    }

    setupEventListeners() {
        // Ricerca
        this.searchInput.addEventListener('input', () => this.handleSearch());
        
        // Modal
        this.addBookBtn.addEventListener('click', () => this.openModal());
        this.modal.querySelectorAll('.close-modal').forEach(btn => {
            btn.addEventListener('click', () => this.closeModal());
        });
        
        // Form
        this.form.addEventListener('submit', (e) => {
            e.preventDefault();
            this.handleSubmit();
        });
        
        // Chiudi modal se si clicca fuori
        this.modal.addEventListener('click', (e) => {
            if (e.target === this.modal) this.closeModal();
        });
    }

    handleSearch() {
        const searchTerm = this.searchInput.value.toLowerCase();
        const filteredBooks = this.books.filter(book => 
            book.title.toLowerCase().includes(searchTerm) ||
            book.author.toLowerCase().includes(searchTerm) ||
            book.tags.some(tag => tag.toLowerCase().includes(searchTerm))
        );
        this.renderBooks(filteredBooks);
    }

    openModal() {
        this.form.reset();
        this.currentEditId = null;
        this.modal.classList.add('active');
        document.body.style.overflow = 'hidden';
    }

    closeModal() {
        this.modal.classList.add('closing');
        setTimeout(() => {
            this.modal.classList.remove('active', 'closing');
            document.body.style.overflow = '';
            this.form.reset();
            this.currentEditId = null;
        }, 300);
    }

    handleSubmit() {
        const bookData = {
            title: document.getElementById('bookTitle').value,
            path: document.getElementById('bookPath').value,
            originalName: document.getElementById('bookPath').dataset.originalName || '',
            tags: document.getElementById('bookTags').value.split(',').map(tag => tag.trim()).filter(tag => tag),
        };

        if (this.currentEditId) {
            const index = this.books.findIndex(book => book.id === this.currentEditId);
            if (index !== -1) {
                this.books[index] = {
                    ...this.books[index],
                    ...bookData,
                    dateModified: new Date().toISOString()
                };
                this.showNotification('Libro aggiornato con successo!');
            }
        } else {
            const newBook = {
                id: Date.now(),
                ...bookData,
                dateAdded: new Date().toISOString()
            };
            this.books.push(newBook);
            this.showNotification('Libro aggiunto con successo!');
        }

        this.saveBooks();
        this.renderBooks();
        this.closeModal();
    }

    renderBooks(booksToShow = this.books) {
        const currentCards = document.querySelectorAll('.book-card');
        currentCards.forEach(card => {
            card.style.animation = 'cardRemove 0.3s ease-out forwards';
        });

        setTimeout(() => {
            this.booksGrid.innerHTML = booksToShow.map(book => {
                // Assicurati che il percorso usi LIbri invece di Libri
                const path = book.path.replace('/Libri/', '/LIbri/');
                return `
                    <div class="book-card" data-id="${book.id}">
                        <div class="book-cover">
                            <span class="material-icons">book</span>
                        </div>
                        <div class="book-info">
                            <h3>${book.title}</h3>
                            <div class="book-tags">
                                ${book.tags.map(tag => `<span class="tag">${tag}</span>`).join('')}
                            </div>
                            <div class="book-path">
                                <span class="file-name">${book.originalName || path.split('/').pop()}</span>
                            </div>
                        </div>
                        <div class="book-actions">
                            <a href="${path}" class="action-btn primary" title="Apri PDF" target="_blank">
                                <span class="material-icons">visibility</span>
                            </a>
                            <button class="action-btn" onclick="bookManager.editBook(${book.id})" title="Modifica">
                                <span class="material-icons">edit</span>
                            </button>
                            <button class="action-btn" onclick="bookManager.deleteBook(${book.id})" title="Elimina">
                                <span class="material-icons">delete</span>
                            </button>
                        </div>
                    </div>
                `;
            }).join('');
        }, currentCards.length ? 300 : 0);
    }

    editBook(id) {
        const book = this.books.find(b => b.id === id);
        if (!book) return;

        this.currentEditId = id;
        document.getElementById('bookTitle').value = book.title;
        document.getElementById('bookPath').value = book.path;
        document.getElementById('bookTags').value = book.tags.join(', ');

        this.modal.classList.add('active');
        document.body.style.overflow = 'hidden';
    }

    deleteBook(id) {
        const modal = document.createElement('div');
        modal.className = 'modal active';
        modal.innerHTML = `
            <div class="modal-content delete-confirm-modal">
                <span class="material-icons icon-warning">warning</span>
                <h2>Conferma Eliminazione</h2>
                <p>Sei sicuro di voler eliminare questo libro?</p>
                <div class="actions">
                    <button class="button-secondary cancel-btn" onclick="bookManager.closeDeleteModal(this)">
                        <span class="material-icons">close</span>
                        No
                    </button>
                    <button class="button-primary confirm-btn" onclick="bookManager.confirmDelete(${id}, this)">
                        <span class="material-icons">delete</span>
                        Sì, elimina
                    </button>
                </div>
            </div>
        `;

        document.body.appendChild(modal);
    }

    closeDeleteModal(buttonElement) {
        const modal = buttonElement.closest('.modal');
        modal.classList.add('closing');
        setTimeout(() => modal.remove(), 300);
    }

    confirmDelete(id, buttonElement) {
        const card = document.querySelector(`[data-id="${id}"]`);
        card.classList.add('removing');
        
        // Prima rimuovi il modal di conferma
        const confirmModal = buttonElement.closest('.modal');
        if (confirmModal) {
            confirmModal.classList.add('closing');
            setTimeout(() => confirmModal.remove(), 300);
        }

        // Poi procedi con l'eliminazione dopo l'animazione
        setTimeout(() => {
            this.books = this.books.filter(book => book.id !== id);
            this.saveBooks();
            this.renderBooks();
            this.showNotification('Libro eliminato con successo');
        }, 300);
    }

    saveBooks() {
        localStorage.setItem('books', JSON.stringify(this.books));
    }

    showNotification(message, type = 'success') {
        const notification = document.createElement('div');
        notification.className = `notification ${type}`;
        notification.textContent = message;
        document.body.appendChild(notification);
        
        setTimeout(() => {
            notification.remove();
        }, 3000);
    }

    setupFileSelection() {
        const selectFileBtn = document.getElementById('selectFileBtn');
        const bookPathInput = document.getElementById('bookPath');
        const fileInput = document.getElementById('bookFileInput');

        selectFileBtn.addEventListener('click', (e) => {
            e.preventDefault();
            fileInput.click();
        });

        fileInput.addEventListener('change', (e) => {
            const file = e.target.files[0];
            if (file) {
                // Usa LIbri invece di Libri nel percorso
                const fileName = file.name;
                const fullPath = `/Dashboard/LIbri/${fileName}`;
                
                bookPathInput.value = fullPath;
                bookPathInput.dataset.originalName = fileName;
            }
        });
    }
}

function showSection(sectionId) {
    // Nascondi tutte le sezioni
    document.querySelectorAll('.subject-grid, .exercise-section').forEach(section => {
        section.style.display = 'none';
    });
    
    // Nascondi tutti i loghi
    document.querySelector('.main-logo').style.display = 'none';
    document.querySelectorAll('.section-logo').forEach(logo => {
        logo.style.display = 'none';
    });
    
    // Mostra la sezione richiesta
    document.getElementById(sectionId).style.display = 
        sectionId === 'subject-selection' ? 'grid' : 'block';
    
    // Mostra il logo appropriato
    if (sectionId === 'subject-selection') {
        document.querySelector('.main-logo').style.display = 'flex';
    } else if (sectionId === 'coding-exercises') {
        document.querySelector('.coding-logo').style.display = 'flex';
    } else if (sectionId === 'books-section') {
        document.querySelector('.books-logo').style.display = 'flex';
    }
}

// Modifica l'inizializzazione per rendere exerciseManager globale
let exerciseManager; // Dichiarazione globale
let bookManager;

document.addEventListener('DOMContentLoaded', () => {
    showSection('subject-selection'); // Mostra la home all'avvio
    new ThemeManager();
    exerciseManager = new ExerciseManager();
    bookManager = new BookManager();
});
