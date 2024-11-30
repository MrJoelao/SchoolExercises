using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Web.Services;
using Delta_Dent;
using MySqlConnector;

namespace Delta_Dent_WebService
{
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    [System.Web.Script.Services.ScriptService]
    public class WebService : System.Web.Services.WebService
    {
        private DbManager _dbManager = new DbManager();

        [WebMethod]
        public string HelloWorld()
        {
            return "Hello World";
        }

        [WebMethod]
        public int Sum(int x, int y)
        {
            return x + y;
        }

        [WebMethod]
        public bool SavePatient(Patient patient)
        {
            // Validate inputs
            if (patient.CheckInputs())
            {
                return false;
            }

            return _dbManager.SavePatientInDb(patient);
        }

        [WebMethod]
        public bool UpdatePatient(Patient patient, int patientId)
        {
            // Validate inputs
            if (patient.CheckInputs())
            {
                return false;
            }

            return _dbManager.UpdatePatientFromId(patient, patientId).Result;
        }

        [WebMethod]
        public bool DeletePatient(int patientId)
        {
            return _dbManager.DeletePatientFromId(patientId).Result;
        }

        [WebMethod]
        public Patient GetPatient(int patientId)
        {
            return _dbManager.GetPatientFromId(patientId).Result;
        }

        [WebMethod]
        public List<Patient> GetPatients(int doctorId, int page, int pageSize)
        {
            return _dbManager.GetPatientsFromDb(doctorId, pageSize, page).Result;
        }

        [WebMethod]
        public bool RegisterDoctor(Doctor doctor)
        {
            // Validate inputs
            if (doctor.CheckInputs(false))
            {
                return false;
            }

            return _dbManager.RegisterDoctorQuery(doctor).Result;
        }

        [WebMethod]
        public bool CheckDoctorExist(string email)
        {
            return _dbManager.CheckDoctorExistAsync(email).Result;
        }

        [WebMethod]
        public bool CheckDoctorCredentials(string email, string password)
        {
            return _dbManager.CheckDoctorCredentialsAsync(email, password).Result;
        }

        [WebMethod]
        public int GetDoctorId(string email)
        {
            return _dbManager.GetDoctorIdAsync(email).Result ?? -1;
        }

        [WebMethod]
        public List<Doctor> GetDoctors(int page, int pageSize)
        {
            return _dbManager.GetDoctorsFromDb(pageSize, page).Result;
        }

        // Test Methods
        [WebMethod]
        public bool TestConnection()
        {
            try
            {
                _dbManager.OpenConnection();
                _dbManager.CloseConnection();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
