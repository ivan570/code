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
    public partial class display_all_books : System.Web.UI.Page
    {
        SqlConnection con = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename='D:\code\.net\library\final done now\final done now\App_Data\lms.mdf';Integrated Security=True");
        protected void Page_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd = con.CreateCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select * from ibooks";
            cmd.ExecuteNonQuery();
            DataTable dt = new DataTable();
            SqlDataAdapter da = new SqlDataAdapter(cmd);
            da.Fill(dt);

            r1.DataSource = dt;
            r1.DataBind();
        }

        public string checkvideo(object myvalue, object id)
        {
            if ((string)myvalue == "")
            {
                return myvalue.ToString();
            }
            else
            {
                return "<a href='delete_files.aspx?id="+id+"' style='color:red'> delete video</a>";
            }
        }
        public string checkpdf(object myvalue1, object id1)
        {
            if ((string)myvalue1 == "")
            {
                return myvalue1.ToString();
            }
            else
            {
                return "<a href='delete_files.aspx?id1=" + id1 + "' style='color:red'> delete video</a>";
            }
        }

    }
}