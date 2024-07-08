using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;
using System.Web.Services;
using Delta_Dent;

namespace Delta_Dent_WebService
{
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    [System.Web.Script.Services.ScriptService]
    public class WebService : System.Web.Services.WebService
    {

        [WebMethod]
        public string HelloWorld()
        {
            return "Hello World";
        }

        [WebMethod(MessageName = "Sum of numbers")]
        public int Sum(int x, int y)
        {
            return x + y;
        }

        [WebMethod]
        public bool SavePatient(string firstName, string surname, bool gender, string telephone,
            string cf, string cAsl, DateTime birthDate, string birthPlace,
            string birthProvince, bool foreigner, string billable, bool completed, bool documented, int doctorId,
            bool locked)
        {
            DbManager db = new DbManager();

            // Create a new patient with the given data
            Patient patient = new Patient(
                firstName,
                surname,
                gender,
                telephone,
                cf,
                cAsl,
                birthDate,
                birthPlace,
                foreigner,
                birthProvince,
                billable,
                completed,
                documented,
                doctorId,
                locked
            );

            // Validate inputs
            if (patient.CheckInputs())
            {
                return false;
            }

            // Save patient in the database
            if (!db.SavePatientInDb(patient))
            {
                return false;
            }

            return true;
        }


        [WebMethod]
        public void SavePatientTest()
        {
            // Dati di test
            string firstName = "Example";
            string surname = "Example";
            bool gender = false;
            string telephone = "Example";
            string cf = "Example";
            string cAsl = "123";
            DateTime birthDate = new DateTime(1980, 1, 1);
            string birthPlace = "Example";
            string birthProvince = "Example";
            bool foreigner = false;
            string billable = "Example";
            bool completed = true;
            bool documented = true;
            int doctorId = 1;
            bool locked = false;

            // Chiamata al metodo SavePatient
            bool result = SavePatient(firstName, surname, gender, telephone, cf, cAsl, birthDate, birthPlace,
                birthProvince, foreigner, billable, completed, documented, doctorId, locked);

            // Stampa il risultato del test
            Console.WriteLine("Result: " + result);
        }
    }
}

