using MySqlConnector;
using System;


namespace Delta_Dent
{
    /// <summary>
    /// Represents a patient in the Delta_Dent system.
    /// </summary>
    public class Patient
    {
        public string FirstName { get; set; }
        public string Surname { get; set; }
        public bool Gender { get; set; } // true = male, false = female
        public string Telephone { get; set; }
        public string Phone1 { get; set; }
        public string Phone2 { get; set; }
        public string CF { get; set; }
        public string CASL { get; set; }
        public DateTime BirthDate { get; set; }
        public string BirthPlace { get; set; }
        public string BirthProvince { get; set; }
        public string Billable { get; set; }
        public bool Completed { get; set; }
        public bool Documented { get; set; }
        public bool Foreigner { get; set; }
        public bool Locked { get; set; }
        public int DoctorID { get; set; }
        public int PatientID { get; set; }

        /// <summary>
        /// Constructor with parameters to initialize a Patient object.
        /// </summary>
        /// <param name="firstName">Patient's first name.</param>
        /// <param name="surname">Patient's surname.</param>
        /// <param name="gender">Patient's gender (true = male, false = female).</param>
        /// <param name="telephone">Patient's telephone number.</param>
        /// <param name="phone1">Patient's alternative phone number 1.</param>
        /// <param name="phone2">Patient's alternative phone number 2.</param>
        /// <param name="cf">Patient's fiscal code.</param>
        /// <param name="cAsl">Patient's ASL code.</param>
        /// <param name="birthDate">Patient's date of birth.</param>
        /// <param name="birthPlace">Patient's place of birth.</param>
        /// <param name="birthProvince">Patient's birth province.</param>
        /// <param name="billable">Indicates if the patient is billable.</param>
        /// <param name="completed">Indicates if the patient's record is completed.</param>
        /// <param name="documented">Indicates if the patient's record is documented.</param>
        /// <param name="foreigner">Indicates if the patient is a foreigner.</param>
        /// <param name="locked">Indicates if the patient's record is locked.</param>
        /// <param name="doctorID">ID of the doctor assigned to the patient.</param>
        /// <param name="PatientID">ID of the patient in the database.</param>
        public Patient(string firstName, string surname, bool gender, string telephone, string phone1, string phone2,
            string cf, string cAsl, DateTime birthDate, string birthPlace, bool foreigner, string birthProvince, string billable,
            bool completed, bool documented, int doctorID, bool locked)
        {
            FirstName = firstName;
            Surname = surname;
            Gender = gender;
            Telephone = telephone;
            Phone1 = phone1;
            Phone2 = phone2;
            CF = cf;
            CASL = cAsl;
            BirthDate = birthDate;
            BirthPlace = birthPlace;
            Foreigner = foreigner;
            BirthProvince = birthProvince;
            Billable = billable;
            Completed = completed;
            Documented = documented;
            DoctorID = doctorID;
            Locked = locked;
        }

        /// <summary>
        /// Default constructor to initialize a Patient object with default values.
        /// </summary>
        public Patient()
        {
            BirthDate = DateTime.Parse("01-01-2000");
        }

        /// <summary>
        /// Checks if any of the required fields are null or empty.
        /// </summary>
        /// <returns>Returns true if all required fields are filled; otherwise, false.</returns>
        public bool CheckInputs()
        {
            // Controlla se uno qualsiasi dei campi è vuoto o nullo
            return !string.IsNullOrEmpty(FirstName) &&
                   !string.IsNullOrEmpty(Surname) &&
                   !string.IsNullOrEmpty(Telephone) &&
                   !string.IsNullOrEmpty(Phone1) &&
                   !string.IsNullOrEmpty(Phone2) &&
                   !string.IsNullOrEmpty(CF) &&
                   !string.IsNullOrEmpty(CASL) &&
                   !string.IsNullOrEmpty(BirthPlace) &&
                   !string.IsNullOrEmpty(BirthProvince) &&
                   !string.IsNullOrEmpty(Billable);
        }

        /// <summary>
        /// Sanitizes patient data to prevent SQL injection.
        /// </summary>
        public void SanitizePatient()
        {
            // Per prevenire SQL injection
            FirstName = SanitizeString(FirstName);
            Surname = SanitizeString(Surname);
            Telephone = SanitizeString(Telephone);
            Phone1 = SanitizeString(Phone1);
            Phone2 = SanitizeString(Phone2);
            CF = SanitizeString(CF);
            CASL = SanitizeString(CASL);
            BirthPlace = SanitizeString(BirthPlace);
            BirthProvince = SanitizeString(BirthProvince);
            Billable = SanitizeString(Billable);
        }

        /// <summary>
        /// Sanitizes a string by escaping single quotes.
        /// </summary>
        /// <param name="input">The input string to sanitize.</param>
        /// <returns>The sanitized string.</returns>
        private string SanitizeString(string input)
        {
            return input.Replace("'", "''");
        }

        /// <summary>
        /// Returns a string representation of the Patient object.
        /// </summary>
        /// <returns>A string that represents the Patient object.</returns>
        public override string ToString()
        {
            return $"ID: {PatientID}, Name: {FirstName} {Surname}, " +
                   $"Gender: {(Gender ? "Male" : "Female")}, " +
                   $"Telephone: {Telephone}, Phone 1: {Phone1}, Phone 2: {Phone2}, " +
                   $"Fiscal Code: {CF}, ASL Code: {CASL}, " +
                   $"Date of Birth: {BirthDate:yyyy-MM-dd}, " +
                   $"Place of Birth: {BirthPlace}, Province of Birth: {BirthProvince}, " +
                   $"Foreigner: {(Foreigner ? "Yes" : "No")}, Billable: {Billable}, " +
                   $"Completed: {(Completed ? "Yes" : "No")}, Documented: {(Documented ? "Yes" : "No")}, " +
                   $"Locked: {(Locked ? "Yes" : "No")}, Doctor ID: {DoctorID}";
        }
    }
}