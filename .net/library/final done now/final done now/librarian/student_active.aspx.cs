using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace final_done_now.librarian
{
    public partial class student_active : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");

        int id;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["librarian"] == null)
            {
                Response.Redirect("login.aspx");
            }
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }

            id = Convert.ToInt32(Request.QueryString["id"].ToString());

            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "update student_registration set approved='yes' where id='" + id + "'";
            cmd.ExecuteNonQuery();

            Response.Redirect("display_student_info.aspx");
        }
    }
}