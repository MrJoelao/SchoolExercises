// Funzione per convertire lunghezze
function convertLength() {
    let input = document.getElementById('inputValue').value;
    let fromUnit = document.getElementById('fromUnit').value;
    let toUnit = document.getElementById('toUnit').value;
    let result = document.getElementById('result');
    
    // Converti tutto in metri prima
    let meters = 0;
    switch(fromUnit) {
        case 'km': meters = input * 1000; break;
        case 'm': meters = input * 1; break;
        case 'cm': meters = input * 0.01; break;
        case 'mm': meters = input * 0.001; break;
    }
    
    // Converti da metri all'unità finale
    let finalValue = 0;
    switch(toUnit) {
        case 'km': finalValue = meters / 1000; break;
        case 'm': finalValue = meters; break;
        case 'cm': finalValue = meters * 100; break;
        case 'mm': finalValue = meters * 1000; break;
    }
    
    result.innerHTML = `${input} ${fromUnit} = ${finalValue} ${toUnit}`;
}

// Funzione per convertire pesi
function convertWeight() {
    let input = document.getElementById('inputValueWeight').value;
    let fromUnit = document.getElementById('fromUnitWeight').value;
    let toUnit = document.getElementById('toUnitWeight').value;
    let result = document.getElementById('resultWeight');
    
    // Converti tutto in grammi prima
    let grams = 0;
    switch(fromUnit) {
        case 'kg': grams = input * 1000; break;
        case 'g': grams = input * 1; break;
        case 'mg': grams = input * 0.001; break;
    }
    
    // Converti da grammi all'unità finale
    let finalValue = 0;
    switch(toUnit) {
        case 'kg': finalValue = grams / 1000; break;
        case 'g': finalValue = grams; break;
        case 'mg': finalValue = grams * 1000; break;
    }
    
    result.innerHTML = `${input} ${fromUnit} = ${finalValue} ${toUnit}`;
}

// Funzione per convertire volumi
function convertVolume() {
    let input = document.getElementById('inputValueVolume').value;
    let fromUnit = document.getElementById('fromUnitVolume').value;
    let toUnit = document.getElementById('toUnitVolume').value;
    let result = document.getElementById('resultVolume');
    
    // Converti tutto in millilitri
    let ml = 0;
    switch(fromUnit) {
        case 'l': ml = input * 1000; break;
        case 'ml': ml = input * 1; break;
    }
    
    // Converti da millilitri all'unità finale
    let finalValue = 0;
    switch(toUnit) {
        case 'l': finalValue = ml / 1000; break;
        case 'ml': finalValue = ml; break;
    }
    
    result.innerHTML = `${input} ${fromUnit} = ${finalValue} ${toUnit}`;
}

// Funzione per convertire dati
function convertData() {
    let input = document.getElementById('inputValueData').value;
    let fromUnit = document.getElementById('fromUnitData').value;
    let toUnit = document.getElementById('toUnitData').value;
    let result = document.getElementById('resultData');
    
    // Converti tutto in bytes prima
    let bytes = 0;
    switch(fromUnit) {
        case 'gb': bytes = input * 1073741824; break; // 1GB = 1024^3 bytes
        case 'mb': bytes = input * 1048576; break;    // 1MB = 1024^2 bytes
        case 'kb': bytes = input * 1024; break;       // 1KB = 1024 bytes
        case 'b': bytes = input * 1; break;
    }
    
    // Converti da bytes all'unità finale
    let finalValue = 0;
    switch(toUnit) {
        case 'gb': finalValue = bytes / 1073741824; break;
        case 'mb': finalValue = bytes / 1048576; break;
        case 'kb': finalValue = bytes / 1024; break;
        case 'b': finalValue = bytes; break;
    }
    
    result.innerHTML = `${input} ${fromUnit} = ${finalValue} ${toUnit}`;
}
