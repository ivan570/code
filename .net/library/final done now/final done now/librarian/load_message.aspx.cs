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
    public partial class load_message : System.Web.UI.Page
    {
        string username = "", msg="";
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
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

        username = Request.QueryString["username"].ToString();
        msg = Request.QueryString["msg"].ToString();
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from messages where (susername='" + username.ToString() + "' and dusername='librarian' )or(  (dusername='" + username.ToString() + "' and susername='librarian' ))";
            cmd.ExecuteNonQuery();

            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);

            foreach(DataRow dr in dt.Rows)
            {
                Response.Write("<p>");
                Response.Write(dr["susername"].ToString() + ":" + dr["msg"].ToString());
                Response.Write("</p>");
                Response.Write("<hr />");
                
                if (dr["dusername"].ToString() == "librarian")
                {
                    SqlCommand cmd1 = con.CreateCommand();
                    cmd1.CommandType = CommandType.Text;
                    cmd1.CommandText = "update message set placed='yes' where id='" + dr["id"].ToString() + "'";
                    cmd1.ExecuteNonQuery();
                }
            }
        }

    }
}