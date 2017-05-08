    <?php
	class select {
		private $name;
        private $value;
        /**
         * @var array
         */
        private $options;
        private $tag = "";



        function __construct($options){

            $this->options = $options;

            $tag =  '<label for="browserPreference">Browser<br/> Preference:  </label>';
            $tag .= '<select id="' . 'browserPreference" name="browserPreference" class="short"> ';
            for($i=0;$i<count($options);$i++){
                $tag .= '<option value="' . $options[$i] . '">' . $options[$i] . '</option>';
            }
            $tag .='</select><br/>';
            echo $tag;
            return;


        }


		public function getName(){
			return $this->name;
		}
		
		public function getValue(){
			return $this->value;
		}
		
		public function setName($name){
			$this->name = $name;
		}
		
		public function setValue($value){
			$this->value = $value;
		}// end class: select
		
	}
	
	


