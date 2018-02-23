<?php

class entryAPI extends simpleAPI {

public $smartClass = 'entry';

  public function getTotalsByMonth() {
    global $user, $login;
    $db = $this->f->db;

    //$sql = "SELECT tag, entrydate, SUM(amount) as total FROM entries GROUP BY tag, DATE_FORMAT(entrydate, '%Y-%m')";
    $sql = "SELECT * FROM `register_vue`.`entries`;";
  	$res = $db->query($sql);
    $this->response['sql'] = $sql;
    $this->response['db'] = var_export($db->host_info, true);
    $this->response['error'] = $db->error;
    $this->response['errno'] = $db->errno;
    $this->response['res'] = var_export($res, true);
    if (is_object($res)) {
      $this->response['success'] = true;
      $this->response['data'] = array();
    /*  while ($row = $res->fetch()) {
        $data = $row->toArray();
        $this->response['data'][] = $data;
      } */
    } else {
      $this->response['success'] = false;
      $this->response['error'] = $q->error;
    }

  }

}
?>
