// Variabili per tenere traccia dello stato della calcolatrice
let displayValue = '';
let lastOperator = '';
let firstNumber = null;
let newNumber = true;
let decimalAdded = false;
let expression = '';

// Funzione per aggiornare il display
function updateDisplay(value) {
    const display = document.getElementById('display');
    display.value = value;
    if (value.length > 12) {
        display.style.fontSize = '1.5rem';
    } else {
        display.style.fontSize = '2rem';
    }
}

// Funzione per aggiungere numeri al display
function appendValue(num) {
    if (num === '.' && decimalAdded) {
        return;
    }
    if (num === '.') {
        decimalAdded = true;
    }

    if (newNumber) {
        displayValue = '';
        newNumber = false;
    }

    if (displayValue.length < 12) {
        displayValue += num;
        if (expression.includes('=')) {
            expression = displayValue;
        } else if (!expression || expression === '0') {
            expression = displayValue;
        } else if (newNumber) {
            expression = expression + displayValue;
        } else {
            let parts = expression.split(' ');
            parts[parts.length - 1] = displayValue;
            expression = parts.join(' ');
        }
        updateDisplay(expression);
        updatePreview();
    }
}

// Funzione per gestire gli operatori
function appendOperator(operator) {
    if (operator === 'clear') {
        displayValue = '';
        firstNumber = null;
        lastOperator = '';
        newNumber = true;
        decimalAdded = false;
        expression = '';
        updateDisplay('0');
        updatePreview();
        return;
    }

    if (firstNumber !== null && !newNumber) {
        calculateResult();
        firstNumber = parseFloat(displayValue);
    } else {
        firstNumber = parseFloat(displayValue);
        if (!expression) {
            expression = displayValue;
        }
    }

    lastOperator = operator;
    newNumber = true;
    decimalAdded = false;

    let operatorSymbol = operator;
    switch(operator) {
        case '*': operatorSymbol = ' × '; break;
        case '/': operatorSymbol = ' ÷ '; break;
        case '+': operatorSymbol = ' + '; break;
        case '-': operatorSymbol = ' - '; break;
    }

    if (!expression.endsWith(' × ') && 
        !expression.endsWith(' ÷ ') && 
        !expression.endsWith(' + ') && 
        !expression.endsWith(' - ')) {
        expression += operatorSymbol;
    } else {
        expression = expression.slice(0, -3) + operatorSymbol;
    }
    
    updateDisplay(expression);
    updatePreview();
}

// Funzione per calcolare il risultato
function calculateResult() {
    if (firstNumber === null || newNumber) {
        return;
    }

    const secondNumber = parseFloat(displayValue);
    let result;

    switch (lastOperator) {
        case '+':
            result = firstNumber + secondNumber;
            break;
        case '-':
            result = firstNumber - secondNumber;
            break;
        case '*':
            result = firstNumber * secondNumber;
            break;
        case '/':
            if (secondNumber === 0) {
                expression = 'Error';
                updateDisplay('Error');
                firstNumber = null;
                newNumber = true;
                decimalAdded = false;
                return;
            }
            result = firstNumber / secondNumber;
            break;
        default:
            return;
    }

    result = Math.round(result * 100000000) / 100000000;
    displayValue = result.toString();
    if (displayValue.length > 12) {
        displayValue = result.toExponential(7);
    }

    expression = expression + displayValue + ' = ' + result;
    updateDisplay(expression);
    
    firstNumber = null;
    newNumber = true;
    decimalAdded = displayValue.includes('.');
    updatePreview();
}

// Aggiungi supporto per la tastiera
document.addEventListener('keydown', function(event) {
    const key = event.key;
    
    // Numeri e punto decimale
    if (/[0-9.]/.test(key)) {
        appendValue(key);
    }
    // Operatori
    else if (['+', '-', '*', '/'].includes(key)) {
        appendOperator(key);
    }
    // Invio o uguale per il risultato
    else if (key === 'Enter' || key === '=') {
        calculateResult();
    }
    // Backspace o Canc per clear
    else if (key === 'Escape' || key === 'Delete') {
        appendOperator('clear');
    }
    // Aggiungiamo il caso per il backspace
    else if (key === 'Backspace') {
        deleteLastDigit();
        event.preventDefault(); // Previene il comportamento predefinito del browser
    }
});

// Inizializza il display
document.addEventListener('DOMContentLoaded', function() {
    updateDisplay('0');
});

// Aggiungi questa funzione per calcolare il preview
function updatePreview() {
    const previewDisplay = document.getElementById('preview-display');
    const display = document.getElementById('display');
    
    if (firstNumber === null || newNumber || !displayValue) {
        previewDisplay.textContent = '';
        previewDisplay.classList.remove('visible');
        display.classList.remove('has-preview');
        return;
    }

    const secondNumber = parseFloat(displayValue);
    let previewResult;

    switch (lastOperator) {
        case '+':
            previewResult = firstNumber + secondNumber;
            break;
        case '-':
            previewResult = firstNumber - secondNumber;
            break;
        case '*':
            previewResult = firstNumber * secondNumber;
            break;
        case '/':
            if (secondNumber === 0) {
                previewResult = 'Error';
            } else {
                previewResult = firstNumber / secondNumber;
            }
            break;
        default:
            previewResult = '';
    }

    if (typeof previewResult === 'number') {
        previewResult = Math.round(previewResult * 100000000) / 100000000;
        if (previewResult.toString().length > 12) {
            previewResult = previewResult.toExponential(7);
        }
    }

    previewDisplay.textContent = previewResult;
    
    requestAnimationFrame(() => {
        display.classList.add('has-preview');
        previewDisplay.classList.add('visible');
    });
}

// Funzione per cancellare l'ultima cifra
function deleteLastDigit() {
    if (expression.includes('=')) {
        return; // Non fare nulla se è stato già calcolato un risultato
    }

    if (expression.length > 0) {
        // Se l'ultimo carattere è uno spazio (parte di un operatore)
        if (expression.endsWith(' ')) {
            expression = expression.slice(0, -3); // Rimuovi l'operatore completo (es. " + ")
            displayValue = expression.split(' ').pop() || ''; // Prendi l'ultimo numero
        } else {
            // Rimuovi l'ultima cifra
            expression = expression.slice(0, -1);
            displayValue = expression.split(' ').pop() || '';
        }

        // Se l'espressione è vuota, mostra 0
        if (expression === '') {
            expression = '0';
            displayValue = '0';
        }

        updateDisplay(expression);
        updatePreview();
    }
}
