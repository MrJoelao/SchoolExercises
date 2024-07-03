using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Web;
using System.Web.Services;
using Delta_Dent;

namespace Delta_Dent_WebService
{
    /// <summary>
    /// Summary description for WebService1
    /// </summary>
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

        [WebMethod(MessageName = "Save patient in the database")]
        public async Task<int> HandleSaveEdit(string firstName, string surname, string genderString, string telephone, string cf, string cAsl, DateTime birthDate, string birthPlace,
            string birthProvince, bool foreigner, string billable, bool completed, bool documented, int doctorId, bool locked)
        {
            DbManager db = new DbManager();

            bool gender = genderString == "f";

            // Creo un nuovo paziente con i dati inseriti
            Patient patient = new Patient(
                firstName,
                surname,
                gender,
                telephone, // Valore predefinito per Telephone
                cf,
                cAsl,
                birthDate,
                birthPlace,
                foreigner,
                birthProvince,
                billable, // Valore predefinito per Billable
                completed, // Valore predefinito per Completed
                documented, // Valore predefinito per Documented
                doctorId, // Casting e not-null assertion
                locked
            );

            // Controllo se gli input sono validi
            if (!patient.CheckInputs())
            {
                return -1;
            }

            if (!await db.SavePatientInDb(patient))
            {
                return -2;
            }

            return 1;
        }
    }
}
