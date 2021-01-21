using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using Newtonsoft.Json.Linq;
using System.Configuration;
using System.Net;
using System.IO;


namespace final_done_now.student
{
    public partial class student_registration : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");

        protected void Page_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            if (Session["student"] == null)
            {
                Response.Redirect("student_login.aspx");
            }
        }

        protected void b1_Click(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }

            int count = 0;
            int count1 = 0;

            if (IsReCaptchValid())
            {
                SqlCommand cmd1 = con.CreateCommand();
                cmd1.CommandType = CommandType.Text;
                cmd1.CommandText = "select * from student_registration where enrollment_no='" + enrollmentno.Text + "'";
                cmd1.ExecuteNonQuery();
                DataTable dt1 = new DataTable();
                SqlDataAdapter da1 = new SqlDataAdapter(cmd1);
                da1.Fill(dt1);
                count = Convert.ToInt32(dt1.Rows.Count.ToString());

                if (count > 0)
                {
                    Response.Write("<script>alert('enrollment number is used') </script>");
                }
                else
                {
                    SqlCommand cmd2 = con.CreateCommand();
                    cmd2.CommandType = CommandType.Text;
                    cmd2.CommandText = "select * from student_registration where username='" + username.Text + "'";
                    cmd2.ExecuteNonQuery();
                    DataTable dt2 = new DataTable();
                    SqlDataAdapter da2 = new SqlDataAdapter(cmd2);
                    da2.Fill(dt2);
                    count1 = Convert.ToInt32(dt2.Rows.Count.ToString());

                    if (count1 > 0)
                    {
                        Response.Write("<script>alert('username number is used') </script>");
                        return;
                    }

                    lblMessage1.Text = "this is valid";
                    f1.SaveAs(Request.PhysicalApplicationPath + "/student/student_img/" + f1.FileName.ToString());
                    string path = "student/student_img/" + f1.FileName.ToString();

                    SqlCommand cmd = con.CreateCommand();
                    cmd.CommandType = CommandType.Text;
                    cmd.CommandText = "insert into student_registration values('" + firstname.Text + "', '" + lastname.Text + "', '" + enrollmentno.Text + "', '" + username.Text + "', '" + password.Text + "', '" + email.Text + "', '" + contact.Text + "', '" + path + "', 'no')";
                    cmd.ExecuteNonQuery();

                    Response.Write("<script>alert('record inserted success') </script>");
                }
            }
            else
            {
                lblMessage1.Text = "this is invalid";
            }

        }
        public bool IsReCaptchValid()
        {
            var result = false;
            var captchaResponse = Request.Form["g-recaptcha-response"];
            var secretKey = "6LeDYzQaAAAAAIzeXN7doqGIsGRzY11cAXXBI6JR";
            var apiUrl = "https://www.google.com/recaptcha/api/siteverify?secret={0}&response={1}";
            var requestUri = string.Format(apiUrl, secretKey, captchaResponse);
            var request = (HttpWebRequest)WebRequest.Create(requestUri);

            using (WebResponse response = request.GetResponse())
            {
                using (StreamReader stream = new StreamReader(response.GetResponseStream()))
                {
                    JObject jResponse = JObject.Parse(stream.ReadToEnd());
                    var isSuccess = jResponse.Value<bool>("success");
                    result = (isSuccess) ? true : false;
                }
            }
            return result;
        }
    }
}